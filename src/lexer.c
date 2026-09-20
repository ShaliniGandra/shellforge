#include <ctype.h>
#include "lexer.h"

void tokenize(const char *input, TokenList *list)
{
    char word[MAX_TOKEN_LEN];
    int pos = 0;

    int single_quote = 0;
    int double_quote = 0;

    init_token_list(list);

    for (int i = 0; input[i] != '\0'; i++)
    {
        char c = input[i];

        /* Single quotes */
        if (c == '\'' && !double_quote)
        {
            single_quote = !single_quote;
            continue;
        }

        /* Double quotes */
        if (c == '"' && !single_quote)
        {
            double_quote = !double_quote;
            continue;
        }

        /* Backslash */
        if (c == '\\' && !single_quote)
        {
            if (input[i + 1] == '\\')
            {
                if (pos < MAX_TOKEN_LEN - 1)
                    word[pos++] = '\\';

                i++;
                continue;
            }

            if (input[i + 1] != '\0' &&
                !isspace((unsigned char)input[i + 1]))
            {
                if (pos < MAX_TOKEN_LEN - 1)
                    word[pos++] = input[++i];

                continue;
            }

            continue;
        }

        /* Space */
        if (isspace((unsigned char)c) &&
            !single_quote &&
            !double_quote)
        {
            if (pos > 0)
            {
                word[pos] = '\0';
                add_token(list, TOKEN_WORD, word);
                pos = 0;
            }

            continue;
        }

        if (pos < MAX_TOKEN_LEN - 1)
            word[pos++] = c;
    }

    if (pos > 0)
    {
        word[pos] = '\0';
        add_token(list, TOKEN_WORD, word);
    }

    add_token(list, TOKEN_END, "END");
}
