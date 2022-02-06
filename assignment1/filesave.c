#include <stdio.h>
#include <stdlib.h>

int main() {
    int roll = 1;
    char name[20];
    char filename[20];

    FILE *fptr;
    
    printf("Enter the name of the file(.txt): ");
    scanf("%s", filename);
    fptr = fopen(filename, "w");

    while (roll != 0) {
        printf("\nEnter name: ");
        scanf("%s", name);
        printf("\nEnter roll: ");
        scanf("%d", &roll);
    
        fputs(name, fptr);
        putw(roll, fptr);
        
        if (roll == 0)
        {
            fclose(fptr);
            break;

        }
    }
    roll = 1;
    
    FILE *bptr;
    
    printf("Enter the name of the file: ");
    scanf("%s", filename);
    bptr = fopen(filename, "wb");

    while (roll != 0) {
        printf("\nEnter name: ");
        scanf("%s", name);
        printf("\nEnter roll: ");
        scanf("%d", &roll);
    
        fputs(name, fptr);
        putw(roll, fptr);
        
        fwrite(&name, sizeof(name), 1, bptr);
        fwrite(&roll, sizeof(roll), 1, bptr);

        if (roll == 0)
        {
            fclose(bptr);
            break;

        }
    }
    return 0;
}
