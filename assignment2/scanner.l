%{
enum 
    {
        TOK_STOP = 0,
        TOK_ADD,
        TOK_SUB,
        TOK_MULT,
        TOK_LOAD,
        TOK_STORE,
        TOK_TRANS,
        TOK_TRIM,
        TOK_DIV,
        TOK_READ,
        TOK_PRINT,
        TOK_LIR,
        TOK_IIR,
        TOK_LOOP,
        TOK_COMMA,
        TOK_NUM,
        TOK_ALPHA,
        TOK_ID,
        TOK_EOF
    };
int count = 0;
%}

%%
\n      {return 0;}
^LOAD {printf("%d", TOK_LOAD);
        count++;}
%%

int yywrap(){}
int main () {
    yylex();
    printf("Number of tokens: %d", count);
    return 0;
}
