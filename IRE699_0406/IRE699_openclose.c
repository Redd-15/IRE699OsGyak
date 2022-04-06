#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fp, sizeoffile;
    char c[100];

    fp = open("IRE699.txt", O_RDWR);
    if (fp == -1) {
        perror("open() -- hiba");
        exit(-1);
    }

    sizeoffile = read(fp, c, 100);
    printf("A read(% d, c, 100). %d byte-ot olvasott ki.\n", fp, sizeoffile);

    lseek(fp, 0, SEEK_SET);
    int result = lseek(fp, 0, SEEK_SET);
    printf("lseek() : %d. karakter az új pozíció\n", result);

    write(fp, c, sizeoffile);

    close(fp);
    return 0;
}
