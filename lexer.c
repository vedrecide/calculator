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
        } 
        // else if ((exp[i] == 'p' && exp[i + 1] == 'i') || (exp[i] == 'P' && exp[i + 1] == 'I')) {
        //     tokens[len].type = NUMBER;
        //     tokens[len].val = PI;

        //     i += 1;
        // } else if (exp[i] == 'e' || exp[i] == 'E') {
        //     tokens[len].type = NUMBER;
        //     tokens[len].val = E;
        // } 
        else if (isalpha((unsigned char) exp[i])) {
            char identifier[32]; // sequence of characters representing a name (pi, e, sqrt, sin, cos, etc...)
            int j = 0;

            while (isalpha((unsigned char) exp[i])) {
                if (j >= 31) {
                    printf("Identifier too long.\n");
                    free(tokens);
                    return NULL;
                }

                identifier[j++] = exp[i++];
            }

            identifier[j] = '\0';
            i--;

            if (strcmp(identifier, "pi") == 0 || strcmp(identifier, "PI") == 0) {
                tokens[len].type = NUMBER;
                tokens[len].val = PI;
            } else if (strcmp(identifier, "e") == 0 || strcmp(identifier, "E") == 0) {
                tokens[len].type = NUMBER;
                tokens[len].val = E;
            } else if (strcmp(identifier, "sqrt") == 0 || strcmp(identifier, "SQRT") == 0) {
                tokens[len].type = SQRT;
            } else if (strcmp(identifier, "sin") == 0 || strcmp(identifier, "SIN") == 0) {
                tokens[len].type = SIN;
            } else if (strcmp(identifier, "cos") == 0 || strcmp(identifier, "COS") == 0) {
                tokens[len].type = COS;
            } else if (strcmp(identifier, "tan") == 0 || strcmp(identifier, "TAN") == 0) {
                tokens[len].type = TAN;
            }
        } else {
            switch (exp[i]) {
                case '(':
                    tokens[len].type = LPAREN;
                    break;
                case ')':
                    tokens[len].type = RPAREN;
                    break;
                case '^':
                    tokens[len].type = POWER;
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
        case SQRT:     return "SQRT";
        case SIN:      return "SIN";
        case COS:      return "COS";
        case TAN:      return "TAN";
        case LPAREN:   return "LPAREN";
        case RPAREN:   return "RPAREN";
        case POWER:    return "POWER";
        case PLUS:     return "PLUS";
        case MINUS:    return "MINUS";
        case MULTIPLY: return "MULTIPLY";
        case DIVIDE:   return "DIVIDE";
        case END:      return "END";
        default:       return "UNKNOWN";
    }
}
