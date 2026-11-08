#ifndef LEXER_H
#define LEXER_H

typedef enum Type {
    NUMBER,
    LPAREN,
    RPAREN,
    POWER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    END
} Type;

typedef struct Token {
    Type type;
    double val;
} Token;

Token *tokenize(char *exp, int *count);

const char *get_type_name(Type type);

#endif
