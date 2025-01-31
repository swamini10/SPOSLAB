#include <stdio.h>

int main()
{
    int p[20], bt[20], pri[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;

    // Print the heading for the program
    printf("\n *** Priority Scheduling Algorithm ***\n");
    
    // Ask the user to enter the number of processes
    printf("\nEnter the number of processes : ");
    scanf("%d", &n);  // Read the number of processes
    
    // Ask the user to enter the burst time and priority for each process
    for (i = 0; i < n; i++)
    {
        p[i] = i;  // Process numbers are assigned in order (0, 1, 2, ...)
        printf("Enter the Burst Time & Priority of Process %d : ", i);  // Prompt for burst time and priority
        scanf("%d %d", &bt[i], &pri[i]);  // Read burst time and priority for the current process
    }

    // Sort the processes based on their priority (higher priority number means higher priority)
    for (i = 0; i < n; i++)
        for (k = i + 1; k < n; k++)
            if (pri[i] > pri[k])  // If the priority of process i is greater than process k, swap
            {
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;

                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                temp = pri[i];
                pri[i] = pri[k];
                pri[k] = temp;
            }

    // Initialize waiting time and turnaround time for the first process
    wtavg = wt[0] = 0;  // Waiting time for the first process is 0
    tatavg = tat[0] = bt[0];  // Turnaround time for the first process is its burst time

    // Calculate waiting times and turnaround times for the remaining processes
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];  // Waiting time for the current process is sum of previous burst times
        tat[i] = tat[i - 1] + bt[i];   // Turnaround time is cumulative burst time
        wtavg = wtavg + wt[i];  // Accumulate total waiting time
        tatavg = tatavg + tat[i];  // Accumulate total turnaround time
    }

    // Print the results in tabular format
    printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    for (i = 0; i < n; i++)
        printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ", p[i], pri[i], bt[i], wt[i], tat[i]);

    // Calculate and display the average waiting time and average turnaround time
    printf("\nAverage Waiting Time is --- %f", wtavg / n);
    printf("\nAverage Turnaround Time is --- %f", tatavg / n);

    return 0;
}

/*
Example Input:

Enter the number of processes : 4
Enter the Burst Time & Priority of Process 0 : 6 2
Enter the Burst Time & Priority of Process 1 : 8 1
Enter the Burst Time & Priority of Process 2 : 7 3
Enter the Burst Time & Priority of Process 3 : 3 4

Example Output:

PROCESS         PRIORITY   BURST TIME   WAITING TIME    TURNAROUND TIME
0               2          6            0               6 
3               4          3            6               9 
2               3          7            9               16
1               1          8            16              24

Average Waiting Time is --- 7.750000
Average Turnaround Time is --- 13.750000
*/
