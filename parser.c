#include "parser.h"

Token current_token(Parser *p) {
    return p->tokens[p->pos];
}

void advance(Parser *p) {
    if (current_token(p).type != END)
        p->pos++;
}

double parse_expression(Parser *p) {}

double parse_term(Parser *p) {}

double parse_factor(Parser *p) {}
