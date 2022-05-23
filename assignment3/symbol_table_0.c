#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 0;

void insert(char lab[], int addr);
void delete(char lab[]);
int search(char lab[]);
void modify();
void display();

struct symbol_table {
    char label[20];
    int addr;
    struct symbol_table *next;
};
struct symbol_table *first, *last;

int main() {
    char lab[] = "AB";
    int addr = 10;
    insert(lab,addr);
    insert("CD", 20);
    insert("XY", 30);
    display();
    delete("XY");
    display();
    return 0;
}


void insert(char lab[],int addr) {
    int n = search(lab);
    if (n == 1)
        printf("Label already exists..\n");
    else {
        struct symbol_table *p;
        p = malloc(sizeof(struct symbol_table));
        strcpy(p->label, lab);
        p->addr = addr;
        p->next = NULL;
        if (size == 0) {
            first = p;
            last = p;
        }
        else {
            last->next = p;
            last = p;
        }
        size++;
        //free(p);

    }
}

int search(char lab[]) {
    int i, flag = 0;
    struct symbol_table *p;
    p = first;
    for (i = 0; i < size; i++) {
        if(strcmp(p->label, lab) ==0)
            flag = 1;
        p = p->next;
    }
    return flag;
}

void delete(char lab[]) {
    int a;
    struct symbol_table *p, *q;
    p = first;
    a = search(lab);
    if (a == 0)
        printf("Label not found..");
    else {
        if (strcmp(first->label, lab) == 0)
            first = first->next;
        else if (strcmp(last->label, lab) == 0) {
            q = p->next;
            while(strcmp(q->label, lab) != 0) {
                p = p->next;
                q = q->next;
            }
            p->next = NULL;
            last = p;
        }
        else {
            q = p->next;
            while(strcmp(q->label, lab) != 0) {
                p = p->next;
                q = q->next;
            }
            p->next = q->next;
        }
        size--;
    }
}

void display() {
    struct symbol_table *p;
    p = first;
    printf("LABEL \t ADDRESS\n");
    for (int i = 0; i <size; i++) {
        printf("%s\t%d\n", p->label, p->addr);
        p = p->next;
    }
}
