%{
#include <stdio.h>
int shift = 3; // Change this value for different shift amounts
%}

%%
[A-Za-z] {
    int encrypted_char = yytext[0] + shift;
    if (yytext[0] >= 'A' && yytext[0] <= 'Z' && encrypted_char > 'Z') {
        encrypted_char -= 26;
    }
    if (yytext[0] >= 'a' && yytext[0] <= 'z' && encrypted_char > 'z') {
        encrypted_char -= 26;
    }
    putchar(encrypted_char);
}

. {
    putchar(yytext[0]);
}

%%

int yywrap() {
    return 1; // Indicate end of input
}

int main() {
    yylex();
    return 0;
}
