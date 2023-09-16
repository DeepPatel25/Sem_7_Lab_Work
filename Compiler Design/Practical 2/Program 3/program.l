%{
int in_comment = 0; // 0 if not in a comment, 1 if in a single-line comment, 2 if in a multi-line comment
%}

%%
"/*" {
    in_comment = 2;
}

"*/" {
    if (in_comment == 2) {
        in_comment = 0;
    }
}

"//" {
    if (in_comment == 0) {
        in_comment = 1;
    }
}

\n {
    if (in_comment == 1) {
        in_comment = 0;
        printf("\n"); // Print a newline to end the single-line comment
    }
}

. {
    if (in_comment > 0) {
        putchar(yytext[0]); // Print characters inside comments
    }
}

%%

int yywrap() {
    return 1; // Indicate end of input
}

int main() {
    yylex();
    return 0;
}
