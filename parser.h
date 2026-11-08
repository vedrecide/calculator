#include "lexer.h"


typedef struct Parser {
    Token *tokens;
    int pos;
} Parser;

Token current_token(Parser *p);

void advance(Parser *p);

/*
Parsing functions
- parse_expression -> Handles +,-
- parse_term -> Handles *,/
- parse_exponents -> Handles exponents
- parse_factor -> Handles numbers, parenthesis, unary operators
*/

double parse_expression(Parser *p);

double parse_term(Parser *p);

double parse_exponents(Parser *p);

double parse_factor(Parser *p);

