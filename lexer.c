#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "lexer.h"

Token* tokenize(char *exp, int *count) {
    Token *tokens = malloc((strlen(exp) + 1) * sizeof(Token));

    if (tokens == NULL)
        return NULL;

    int len = 0;
    char *endptr;
    for (int i = 0; exp[i] != '\0' && exp[i] != '\n'; i++) {
        if (isdigit((unsigned char) exp[i]) || exp[i] == '.') {
            tokens[len].type = NUMBER;
            tokens[len].val = strtod(&exp[i], &endptr);

            if (endptr == &exp[i]) {
                free(tokens);
                return NULL;
            }

            i = endptr - exp - 1; // to the last character consumed, then the for loop will increment i to the next character.
        } else if (isspace((unsigned char) exp[i])) {
            continue;
        } else {
            switch (exp[i]) {
                case '(':
                    tokens[len].type = LPAREN;
                    break;
                case ')':
                    tokens[len].type = RPAREN;
                    break;
                case '+':
                    tokens[len].type = PLUS;
                    break;
                case '-':
                    tokens[len].type = MINUS;
                    break;
                case '*':
                    tokens[len].type = MULTIPLY;
                    break;
                case '/':
                    tokens[len].type = DIVIDE;
                    break;
                default:
                    printf("Invalid token '%c'\n", exp[i]);
                    free(tokens);
                    return NULL;
            }
        }
        len++;
    }

    *count = len;
    tokens[len].type = END;

    return tokens;
}

const char* get_type_name(Type type) {
    switch (type) {
        case NUMBER:   return "NUMBER";
        case LPAREN:   return "LPAREN";
        case RPAREN:   return "RPAREN";
        case PLUS:     return "PLUS";
        case MINUS:    return "MINUS";
        case MULTIPLY: return "MULTIPLY";
        case DIVIDE:   return "DIVIDE";
        case END:      return "END";
        default:       return "UNKNOWN";
    }
}
