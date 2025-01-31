#include <stdio.h>

int main()
{
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;

    // Print the heading for the program
    printf("\n *** Shortest Job First Scheduling Algorithm *** ");
    
    // Ask the user to enter the number of processes
    printf("\nEnter the number of processes : ");
    scanf("%d", &n);  // Read the number of processes
    
    // Ask the user to enter the burst time for each process
    for (i = 0; i < n; i++)
    {
        p[i] = i;  // Process numbers are assigned in order (0, 1, 2, ...)
        printf("Enter Burst Time for Process %d : ", i);  // Prompt for burst time of process i
        scanf("%d", &bt[i]);  // Read burst time for the current process
    }

    // Sort the processes based on their burst times in ascending order (Shortest Job First)
    for (i = 0; i < n; i++)
        for (k = i + 1; k < n; k++)
            if (bt[i] > bt[k])
            {
                // Swap the burst times
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;

                // Swap the process IDs (to maintain the correct order of processes)
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }

    // Initialize waiting time and turnaround time for the first process
    wt[0] = wtavg = 0;  // Waiting time for first process is 0
    tat[0] = tatavg = bt[0];  // Turnaround time for first process is its burst time

    // Calculate waiting times and turnaround times for the remaining processes
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];  // Waiting time for the current process is sum of previous burst times
        tat[i] = tat[i - 1] + bt[i];   // Turnaround time is cumulative burst time
        wtavg = wtavg + wt[i];  // Accumulate total waiting time
        tatavg = tatavg + tat[i];  // Accumulate total turnaround time
    }

    // Print the results in tabular format
    printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for (i = 0; i < n; i++)
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]);

    // Calculate and display the average waiting time and average turnaround time
    printf("\nAverage Waiting Time : %f", wtavg / n);
    printf("\nAverage Turnaround Time : %f", tatavg / n);

    return 0;
}

/*
Example Input:

Enter the number of processes : 4
Enter Burst Time for Process 0 : 6
Enter Burst Time for Process 1 : 8
Enter Burst Time for Process 2 : 7
Enter Burst Time for Process 3 : 3

Example Output:

	 PROCESS 	BURST TIME 	 WAITING TIME	 TURNAROUND TIME
	 P3 		 3 		 0 		 3
	 P0 		 6 		 3 		 9
	 P2 		 7 		 9 		 16
	 P1 		 8 		 16 		 24

Average Waiting Time : 7.000000
Average Turnaround Time : 13.000000
*/
