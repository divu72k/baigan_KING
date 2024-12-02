#include<stdio.h>

#define max 25

void main()
{
    int frag[max], b[max], f[max], i, j, nb, nf, temp, highest = 0;
    static int bf[max], ff[max];

    printf("\n\tMemory Management Scheme - Worst Fit");

    printf("\nEnter the number of blocks:");
    scanf("%d", &nb);

    printf("Enter the size of the blocks:-\n");
    for(i = 1; i <= nb; i++)
    {
        printf("Block %d:", i);
        scanf("%d", &b[i]);
    }

    printf("Enter the number of files:");
    scanf("%d", &nf);

    printf("Enter the size of the files :-\n");
    for(i = 1; i <= nf; i++)
    {
        printf("File %d:", i);
        scanf("%d", &f[i]);
    }

    for(i = 1; i <= nf; i++)
    {
        int allocated = 0;
        for(j = 1; j <= nb; j++)
        {
            if(bf[j] != 1) // if bf[j] is not allocated
            {
                temp = b[j] - f[i];
                if(temp >= 0) // if the remaining block size is larger than the file size
                {
                    if(highest < temp) // if the largest remaining block size is smaller than the current largest remaining block size
                    {
                        highest = temp; // update the largest remaining block size
                        ff[i] = j; // update the block number
                    }
                }
            }
        }
        if(highest == 0) // if no suitable block was found
        {
            printf("\nMemory not available for file %d", i);
            break;
        }
        else
        {
            frag[i] = highest; // store the fragmentation for the file
            bf[ff[i]] = 1; // mark the allocated block
            highest = 0; // reset the largest remaining block size
        }
    }

    printf("\nFile_no:\tFile_size:\tBlock_no:\tBlock_size:\tFragement");
    for(i = 1; i <= nf; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, f[i], ff[i], b[ff[i]], frag[i]);
}