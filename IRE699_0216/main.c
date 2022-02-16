#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp=fopen("IRE699.txt","wt");
    char c;

    if (fp == NULL) {printf("Sikertelen a fa'jl le'trehozasa!"); return -1;}
    else {

        fprintf(fp, "Sikora Da'vid A'dam \nMe'rnokinformatika\nIRE699\n...");

        fflush(fp);
        fclose(fp);
    }

    FILE *fp2;
    fp2=fopen("IRE699.txt","rt");
    if (fp2 == NULL) {printf("Sikertelen a fa'jl megnyita'sa!");}
    else {

        while((c = fgetc(fp2)) != EOF){
                printf("%c",c);
        }
    fclose(fp2);
    }

    return 0;
}
