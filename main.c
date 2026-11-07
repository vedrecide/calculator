#include <stdio.h>
#include <string.h>

#include "lexer.h"
#include "parser.h"


int main(int argc, char *argv[]) {
    char exp[100];
    int count = 0;
    while (1) {
        printf(">> ");
        if (fgets(exp, sizeof(exp), stdin) == NULL) break; // handling EOF

        if (strcmp(exp, "exit\n") == 0) break;

        Token *tokens = tokenize(exp, &count);

        if (tokens == NULL) {
            printf("Tokenization failed.\n");
            continue;
        }

        Parser p = {
            .tokens = tokens,
            .pos = 0
        };

        double result = parse_expression(&p);

        // for (int i = 0; i < count; i++) {
        //     if (tokens[i].type == NUMBER)
        //         printf("%s: %.2f\n", get_type_name(tokens[i].type), tokens[i].val);
        //     else
        //         printf("%s\n", get_type_name(tokens[i].type));
        // }

        printf("%.4f\n", result);
    }

    return 0;
}