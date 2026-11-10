#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "parser.h"

Token current_token(Parser *p) {
    return p->tokens[p->pos];
}

void advance(Parser *p) {
    if (current_token(p).type != END)
        p->pos++;
}

double parse_expression(Parser *p) {
    double left = parse_term(p);

    while (current_token(p).type == PLUS || current_token(p).type == MINUS) {

        Token op = current_token(p);
        advance(p);

        double right = parse_term(p);

        if (op.type == PLUS) {
            left += right;
        } else {
            left -= right;
        }
    }

    return left;
}

double parse_term(Parser *p) {
    double left = parse_exponents(p);

    while (current_token(p).type == MULTIPLY || current_token(p).type == DIVIDE) {

        Token op = current_token(p);
        advance(p);

        double right = parse_exponents(p);

        if (op.type == MULTIPLY) {
            left *= right;
        } else {
            left /= right;
        }
    }

    return left;
}

double parse_exponents(Parser *p) {
    double left = parse_factor(p);

    if (current_token(p).type == POWER) {
        advance(p);

        double right = parse_exponents(p);

        return pow(left, right);
    }

    return left;
}

double parse_factor(Parser *p) {
    Token t = current_token(p);

    if (t.type == NUMBER) {
        advance(p);
        return t.val;
    }

    if (t.type == LPAREN) {
        advance(p);
        double result = parse_expression(p);

        if (current_token(p).type != RPAREN) {
            printf("Expected closing parenthesis, got %s instead\n", get_type_name(current_token(p).type));
            exit(1);
        }

        advance(p);
        return result;
    }

    if (t.type == PLUS || t.type == MINUS) {
        Type unary = t.type;
        advance(p);
        double value = parse_factor(p);
        return (unary == PLUS) ? value : -value;
    }

    if (t.type == SQRT || t.type == SIN || t.type == COS || t.type == TAN) {
        Type function = t.type;

        advance(p);

        if (current_token(p).type != LPAREN) {
            printf("Expected opening parenthesis, got %s instead.\n", get_type_name(current_token(p).type));
            exit(1);
        }

        advance(p);

        double expression = parse_expression(p);

        if (current_token(p).type != RPAREN) {
            printf("Expected closing parenthesis, got %s instead.\n", get_type_name(current_token(p).type));
            exit(1);
        }

        advance(p);

        switch (function) {
            case SQRT: return sqrt(expression);
            case SIN:  return sin(expression);
            case COS:  return cos(expression);
            case TAN:  return tan(expression);
        }
    }

    printf("Unexpected token type: %s\n", get_type_name(t.type));
    exit(1);
}
