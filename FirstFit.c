#include<stdio.h>
#define max 25

int main() {
    int frag[max], b[max], f[max], i, j, nb, nf, temp;
    static int bf[max], ff[max];
    int flag, flagn[max], fragi = 0, fragx = 0;

    // Prompt user for the number of blocks and processes
    printf("\n\t *** Memory Management Scheme - First Fit ***");
    printf("\nEnter the number of blocks: ");
    scanf("%d", &nb);
    printf("Enter the number of Process: ");
    scanf("%d", &nf);

    // Input the size of each memory block
    printf("\nEnter the size of the blocks:-\n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d: ", i);
        scanf("%d", &b[i]);
        ff[i] = i;  // Initialize block indices
    }

    // Input the size of each process
    printf("Enter the size of the Processes :-\n");
    for (i = 1; i <= nf; i++) {
        printf("Process %d: ", i);
        scanf("%d", &f[i]);
    }

    int x = 1;
    printf("\n\nProcess_No\tProcess_Size\tBlock_No\tBlock_Size\tFragment\n");

    // Try to allocate each process to the first block that fits
    for (i = 1; i <= nf; i++) {
        flag = 1;  // Flag to check if a process has been allocated
        for (j = x; j <= nb; j++) {
            if (f[i] <= b[j]) {  // If process can fit into the block
                flagn[j] = 1;  // Mark block as allocated
                printf("%-15d\t%-15d\t%-15d\t%-15d\t", i, f[i], ff[j], b[j]);
                b[j] = b[j] - f[i];  // Reduce block size
                fragi = fragi + b[j];  // Add remaining memory (fragmentation)
                printf("%-15d\n", b[j]);
                break;
            } else {
                flagn[j] = 0;  // If block cannot fit process
                flag++;  // Increment flag if no block is suitable
            }
        }
        // If no block could fit the process, display "WAIT..."
        if (flag > nb)
            printf("%-15d\t%-15d\t%-15s\t%-15s\t%-15s\n", i, f[i], "WAIT...", "WAIT...", "WAIT...");
    }

    return 0;
}

/*
Example Input:

Enter the number of blocks: 3
Enter the number of Process: 3

Enter the size of the blocks:-
Block 1: 100
Block 2: 500
Block 3: 200

Enter the size of the Processes :-
Process 1: 212
Process 2: 417
Process 3: 112

Example Output:

Process_No   Process_Size   Block_No   Block_Size   Fragment
1            212            2           500           288
2            417            3           200           0
3            112            1           100           WAIT... WAIT... WAIT...
*/
