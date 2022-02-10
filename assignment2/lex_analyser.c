#include <stdio.h>
#include <stdlib.h>
#include "token.h"

// global variables
extern FILE *fptr;
char tokstr[100];

// global functions
char *getstr(int n);
void *ungetstr(char str[]);

int token_analyser () {
    int i = 0;
    int ch;
    
    while ((ch = fgetc(fptr)) != EOF) {
        switch(ch) {
            case ';':
                    return (TOK_SEMICOLON);

            case ',':
                    tokstr[0]=',';
                    tokstr[1] = '\0';
                     return (TOK_COMMA);
            case ''':
                    tokstr[0] = ''';
                    char ch1 = fgetc(fptr);
                    char ch2 = fgetc(fptr);
                    if (ch2 = ''') {
                        tokstr[1] = ch1;
                        ungetc(ch1);
                        ungetc(ch2);
                        return (TOK_NUM);
                    }
            //imperative cases
            case 'S':
                    char ch1[4];
                    int i = 0;
                    while (i != 4) {
                        ch1[i] = fgetc(fptr);
                        switch(i) {
                            case 0:
                                if (ch1[0] = 'T' || ch1[0] = 'U')
                                    i++;
                                break;
                            case 1:
                                if (ch[1] = 'O' || ch1[1] = 'A')
                                    i++;
                                if (ch1[1] = 'B')
                                    return (TOK_SUB);
                                break;
                            case 2:
                                if (ch1[2] = 'P')
                                    return (TOK_STOP);
                                if (ch1[2] = 'R')
                                    i++;
                                else
                                    break;
                            case 3:
                                if (ch[2] = 'P' && ch[3] ='\0')
                                    i++;
                                break;
                            case 4:
                                if (ch[3] = 'T')
                                    i++;
                                    return (TOK_START);
                            default:
                                break;

                        }
                        // if (ch1[i] = "T") {
                        //     i++;
                        //     if (ch[i])
                        // }
                    }
            case 'L':
                    char ch1[4];
                    int i = 0;

                    ch1 = getstr(4);
                    
                    switch(i) {
                        case 0:
                            if (ch1[0] = 'O' || ch1[0] = 'I')
                                i++;
                            else
                                break;
                        case 1:
                            if (ch1[1] = 'A')
                                i++;
                            if (ch1[1] = 'R' && ch1[2] = NULL)
                                return (TOK_LIR);
                            break;
                        case 2:
                            if (ch1[2] = 'D')
                                return (TOK_LOAD);
                            else
                                break;
                        default:
                            break;
                    }
                    ungetstr(ch1);
                   
            case 'A':
                    char ch1[2]:
                    int i = 0;

                    ch1 = getstr(2);

                    for (i = 0; i < strlen(ch1);) {
                        switch(i) {
                            case 0:
                                if (ch1[0] = 'D')
                                    i++;
                                else
                                    break;
                            case 1:
                                if (ch1[1] = 'D' && ch1[2] = '\0')
                                    return (TOK_ADD);
                                else
                                    break;
                            default:
                                break;
                        }
                    }
                    ungetstr(ch1);

            case 'M':
                    char ch1[3];
                    int i = 0;

                    ch1 = getstr(3);
                    if (ch1[0] = 'U' && ch1[1] = 'L' && ch1[2] = 'T' && ch1[3] = '\0')
                        return (TOK_MULT);
                    else
                        break;
                        
                    ungetstr(ch1);

            case 'D':
                    char ch1[2];
                    int i = 0;

                    ch1 = getstr(2);

                    if (ch1[0] = 'I' && ch1[1] = 'V' && ch1[3] = '\0')
                        return (TOK_DIV);
                    else
                        break;
                        
                    ungetstr(ch1);

            case 'T':
                    char ch1[4];
                    int i = 0;
                    
                    ch1 = getstr(4);

                    if (ch1[0] = 'R' && ch1[1] = 'A' && ch1[2] = 'N' && ch1[3] = 'S' && ch1[4] = '\0')
                        return (TOK_TRANS);
                    if (ch1[0] = 'R' && ch1[1] = 'I' && ch1[2] = 'M' && ch1[3] = '\0')
                        return (TOK_TRIM);
                    else
                        break;
                        
                    ungetstr(ch1);

            case 'P':
                    char ch1[3];
                    int i = 0;
                    ch1 = getstr(3);

                    if (ch1[0] = 'R' && ch1[1] = 'I' && ch1[2] = 'N' && ch1[3] = 'T' && ch1[4] = '\0')
                        return (TOK_PRINT);
                    else
                        break;
                        
                    ungetstr(ch1); 
        }
    }
}

char *getstr(int n) {
    char *str;
    int i = 0;
    while (i != n) {
        str[i] = fgetc(fptr);
        i++;
    }
    return str;
}

void *ungetstr(char str[]) {
    int i = 0;
    while (i != strlen(str)) {
        str[i] = ungetc(fptr);
        i++;
    }
}
