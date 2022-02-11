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
        TOK_EOF,
        TOK_IDENTIFIER,
        TOK_INTEGER
    };
int tokCount = 0;
char string[20];
%}

%%
end      {return 0;}
"LOAD" {printf("%d", TOK_LOAD);
        tokCount++;}

"ADD" {printf("%d ", TOK_ADD);
        tokCount++;}
"SUB" {printf("%d ", TOK_SUB);
        tokCount++;}
"STORE" {printf("%d ", TOK_STORE);
        tokCount++;}
"DIV" {printf("%d ", TOK_DIV);
        tokCount++;}
"READ" {printf("%d ", TOK_READ);
        tokCount++;}
"PRINT" {printf("%d ", TOK_PRINT);
        tokCount++;}
[,]     {printf("%d ", TOK_COMMA);
        tokCount++;}

[a-zA-Z][_a-zA-Z0-9]*   {printf("%d ", TOK_IDENTIFIER);
                        strcpy(string,yytext);
                        printf("(%s) ", string);
                        tokCount++;}
[1-9][0-9]* {printf("%d ", TOK_INTEGER);
            strcpy(string, yytext);
            printf("(%s) ", string);
            tokCount++;}
[ \t\n] ;

.   {printf("Unxpected char\n");}
%%

int yywrap(){}
int main (int argc, char *argv[]) {
    FILE *fp;
    char filename[50];
    fp = fopen(argv[1], "r");
    yyin = fp;

    yylex();
    printf("Number of tokens: %d\n", tokCount);
    return 0;
}
