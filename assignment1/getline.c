#include <stdio.h>
#include <string.h>

#define MAX 1000

int getlines(char *line, FILE *fptr);

int main() {
    FILE *fptr = fopen("input.txt", "r");

    char lines[MAX];
    int len;
    int i = 1;

    while ((len = getlines(lines, fptr)) > 0) {
        printf("%d %s", i, lines);
        i++;
    }
    
    fclose(fptr);
}

int getlines (char *line, FILE *fptr) {
    if (fgets(line, MAX, fptr) == NULL)
        return 0;
    else
        return strlen(line);
}
