#include <stdio.h>
#include <string.h>
#include "lexer.h"
#include "token.h"
#include "builtin.h"

#define MAX_ARGS 64

static void print_pipeline(TokenList *list)
{
    printf("\n========== PIPELINE ==========\n\n");

    printf("Command 1\n");
    printf("------------------------------\n");
    printf("Arguments\n");

    int arg = 0;

    for (int i = 0; i < list->count; i++)
    {
        if (list->tokens[i].type == TOKEN_END)
            break;

        if (arg < MAX_ARGS)
        {
            printf("argv[%d] = %s\n", arg, list->tokens[i].value);
            arg++;
        }
    }

    printf("Input     : None\n");
    printf("Output    : None\n");
    printf("Append    : No\n");
    printf("Background: No\n");
    printf("==============================\n");
}

static void run_builtin(TokenList *list)
{
    char *argv[MAX_ARGS];
    int argc = 0;

    for (int i = 0; i < list->count; i++)
    {
        if (list->tokens[i].type == TOKEN_END)
            break;

        if (argc < MAX_ARGS - 1)
            argv[argc++] = list->tokens[i].value;
    }

    argv[argc] = NULL;

    if (argc == 0)
        return;

    if (strcmp(argv[0], "cd") == 0)
    {
        builtin_cd(argv);
    }
    else if (strcmp(argv[0], "pwd") == 0)
    {
        builtin_pwd();
    }
    else if (strcmp(argv[0], "echo") == 0)
    {
        builtin_echo(argv);
    }
    else if (strcmp(argv[0], "exit") == 0)
    {
        builtin_exit(argv);
    }
}

int main(void)
{
    char input[1024];

    printf("====================================\n");
    printf("        Shellforge\n");
    printf(" A Unix Style Shell written in C\n");
    printf("====================================\n");

    while (1)
    {
        printf("shellforge$ ");

        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0)
            continue;

        TokenList list;

        tokenize(input, &list);

        print_tokens(&list);

        print_pipeline(&list);

        run_builtin(&list);
    }

    return 0;
}
