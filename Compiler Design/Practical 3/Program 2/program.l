%{
#include<stdio.h>
int flag = 0;
%}
%%
and |
or |
but |
because |
if |
then |
nevertheless { flag = 1; }
.;
\n { return 0; }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter the statement : \n");
    yylex();
    if(flag == 0) {
        printf("Simple statement.\n");
    }
    else {
        printf("Compound statement.\n");
    }
}