#include <stdio.h>

int main() {
    int f[50], i, st, len, c;

    // Initialize the file allocation array
    for (i = 0; i < 50; i++) {
        f[i] = 0;
    }

    do {
        printf("\n Enter the starting block & length of file: ");
        scanf("%d%d", &st, &len);

        // Check if the starting block is already allocated
        if (f[st] == 1) {
            printf("Block already allocated\n");
            continue;
        }

        // Allocate the file to disk
        for (i = st; i < (st + len); i++) {
            f[i] = 1;
            printf("\n%d->%d", i, f[i]);
        }

        printf("\n the file is allocated to disk");
        printf("\n if u want to enter more files?(y-1/n-0) ");
        scanf("%d", &c);
    } while (c == 1);

    return 0;
}