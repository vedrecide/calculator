#ifndef LEXER_H
#define LEXER_H

#define PI 3.14159265358979323846
#define E  2.71828182845904523536

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
