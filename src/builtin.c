#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "builtin.h"

int builtin_cd(char **argv)
{
    char *dir;

    if (argv[1] == NULL)
    {
        dir = getenv("HOME");

        if (dir == NULL)
        {
            fprintf(stderr, "cd: HOME not set\n");
            return 1;
        }
    }
    else if (argv[2] == NULL)
    {
        dir = argv[1];
    }
    else
    {
        fprintf(stderr, "cd: too many arguments\n");
        return 1;
    }

    if (chdir(dir) != 0)
    {
        perror("cd");
        return 1;
    }

    return 0;
}

int builtin_pwd(void)
{
    printf("ID: 2500031987\n");

    char cwd[PATH_MAX];

    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        perror("pwd");
        return 1;
    }

    printf("%s\n", cwd);

    return 0;
}

int builtin_echo(char **argv)
{
    int i = 1;

    while (argv[i] != NULL)
    {
        if (i > 1)
            printf(" ");

        printf("%s", argv[i]);

        i++;
    }

    printf("\n");

    return 0;
}

int builtin_exit(char **argv)
{
    if (argv[1] != NULL)
    {
        fprintf(stderr, "exit: too many arguments\n");
        return 1;
    }

    exit(0);
}
