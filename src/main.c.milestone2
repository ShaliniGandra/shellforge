#include <stdio.h>
#include <string.h>
#include "lexer.h"
#include "token.h"

#define MAX_HISTORY 100

int main(void)
{
    char input[1024];
    char history[MAX_HISTORY][1024];
    int history_count = 0;

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

        /* Exit */
        if (strcmp(input, "exit") == 0)
        {
            printf("Exiting...\n");
            break;
        }

        /* History */
        if (strcmp(input, "history") == 0)
        {
            printf("\n------ Command History ------\n");

            for (int i = 0; i < history_count; i++)
                printf("%d  %s\n", i + 1, history[i]);

            printf("-----------------------------\n");
            continue;
        }

        /* Store command in history */
        if (history_count < MAX_HISTORY)
        {
            strcpy(history[history_count], input);
            history_count++;
        }

        TokenList list;

        tokenize(input, &list);

        print_tokens(&list);
    }

    return 0;
}
