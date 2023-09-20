%{
#include<stdio.h>
%}

%%
\<[^>]*\> { printf(yyout, "%s%n", yytext); }
.^n;
%%

int yywrap() {
    return 1;
}

int main() {
    yyin = fopen("test.html", "r");
    yyout = fopen("output.txt", "w");
    yylex();
    return 0;
}