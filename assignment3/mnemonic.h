#ifndef MNEMONIC_H
#define MNEMONIC_H

struct mnemonic { 
    char instr[20];
    int opcode;
    //char oper1[20], oper2[20];
    struct mnemonic *next;
};


void insert(char lab[], int addr);
void del(char lab[]);
int search(char lab[]);
void display();

#endif
