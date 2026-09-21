#include <stdio.h>
#include <string.h>
#include "token.h"

void init_token_list(TokenList *list)
{
    list->count = 0;
}

void add_token(TokenList *list, TokenType type, const char *value)
{
    if (list->count >= MAX_TOKENS)
        return;

    list->tokens[list->count].type = type;

    strncpy(list->tokens[list->count].value,
            value,
            MAX_TOKEN_LEN - 1);

    list->tokens[list->count].value[MAX_TOKEN_LEN - 1] = '\0';

    list->count++;
}

void print_tokens(const TokenList *list)
{
    printf("\n------------- TOKENS -------------\n");

    for (int i = 0; i < list->count; i++)
    {
        if (list->tokens[i].type == TOKEN_WORD)
        {
            printf("%d : WORD          %s\n",
                   i,
                   list->tokens[i].value);
        }
        else if (list->tokens[i].type == TOKEN_BACKGROUND)
        {
            printf("%d : BACKGROUND    &\n", i);
        }
        else if (list->tokens[i].type == TOKEN_END)
        {
            printf("%d : END           END\n", i);
        }
    }

    printf("----------------------------------\n");
}
