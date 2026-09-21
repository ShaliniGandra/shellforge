#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#include "executor.h"
#include "builtin.h"

#define MAX_ARGS 64

static int is_builtin(const char *command)
{
    if (strcmp(command, "cd") == 0)
        return 1;

    if (strcmp(command, "pwd") == 0)
        return 1;

    if (strcmp(command, "echo") == 0)
        return 1;

    if (strcmp(command, "exit") == 0)
        return 1;

    return 0;
}

static int run_builtin(char **argv)
{
    if (strcmp(argv[0], "cd") == 0)
        return builtin_cd(argv);

    if (strcmp(argv[0], "pwd") == 0)
        return builtin_pwd();

    if (strcmp(argv[0], "echo") == 0)
        return builtin_echo(argv);

    if (strcmp(argv[0], "exit") == 0)
        return builtin_exit(argv);

    return 0;
}

int execute_command(TokenList *list)
{
    char *argv[MAX_ARGS];
    int argc = 0;
    int background = 0;

    /*
     * Check whether the last argument is '&'.
     * '&' should NOT be passed to the external command.
     */
    for (int i = 0; i < list->count; i++)
    {
        if (list->tokens[i].type == TOKEN_END)
            break;

        if (strcmp(list->tokens[i].value, "&") == 0)
        {
            background = 1;
            continue;
        }

        if (argc < MAX_ARGS - 1)
            argv[argc++] = list->tokens[i].value;
    }

    argv[argc] = NULL;

    if (argc == 0)
        return 0;

    /*
     * Built-in commands run in the parent shell.
     */
    if (is_builtin(argv[0]))
        return run_builtin(argv);

    /*
     * Ignore SIGCHLD so completed background
     * processes do not remain as zombies.
     */
    if (background)
        signal(SIGCHLD, SIG_IGN);

    /*
     * External command execution.
     */
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {
        execvp(argv[0], argv);

        perror("execvp");
        exit(1);
    }

    /*
     * Background command:
     * Do NOT wait for the child.
     */
    if (background)
    {
        printf("[Background PID: %d]\n", pid);
        return 0;
    }

    /*
     * Foreground command:
     * Wait for the child to finish.
     */
    int status;

    if (waitpid(pid, &status, 0) < 0)
    {
        perror("waitpid");
        return 1;
    }

    if (WIFEXITED(status))
        return WEXITSTATUS(status);

    return 1;
}
