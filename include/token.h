#ifndef TOKEN_H
#define TOKEN_H

#define MAX_TOKENS 64
#define MAX_TOKEN_LEN 256

typedef enum {
    TOKEN_WORD,
    TOKEN_END
} TokenType;

typedef struct {
    TokenType type;
    char value[MAX_TOKEN_LEN];
} Token;

typedef struct {
    Token tokens[MAX_TOKENS];
    int count;
} TokenList;

void init_token_list(TokenList *list);
void add_token(TokenList *list, TokenType type, const char *value);
void print_tokens(const TokenList *list);

#endif
