#include <stdio.h>

int main()
{
    int bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;

    // Print the heading for the program
    printf("\n *** First Come First Serve Scheduling Algorithm ***\n ");
    
    // Ask the user to enter the number of processes
    printf("\nEnter the number of processes :");
    scanf("%d", &n);  // Read the number of processes
    
    // Ask the user to enter the burst time for each process
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Burst Time for Process %d : ", i);  // Display process number
        scanf("%d", &bt[i]);  // Read burst time for the current process
    }
    
    // Initialize the waiting time and turnaround time for the first process
    wt[0] = wtavg = 0;  // First process has no waiting time
    tat[0] = tatavg = bt[0];  // Turnaround time for the first process is equal to its burst time
    
    // Calculate waiting times and turnaround times for subsequent processes
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];  // Waiting time for the current process is the sum of burst times of previous processes
        tat[i] = tat[i - 1] + bt[i];   // Turnaround time is the cumulative burst time
        wtavg = wtavg + wt[i];  // Add the current waiting time to the total
        tatavg = tatavg + tat[i];  // Add the current turnaround time to the total
    }
    
    // Print the table header
    printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");

    // Print the details for each process
    for (i = 0; i < n; i++)
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", i, bt[i], wt[i], tat[i]);
    
    // Print the average waiting time and average turnaround time
    printf("\nAverage Waiting Time : %f", wtavg / n);
    printf("\nAverage Turnaround Time : %f", tatavg / n);

    return 0;
}

/*
Example Input:

Enter the number of processes: 4
Enter Burst Time for Process 0: 4
Enter Burst Time for Process 1: 4
Enter Burst Time for Process 2: 4
Enter Burst Time for Process 3: 4

Example Output:

	 PROCESS 	BURST TIME 	 WAITING TIME	 TURNAROUND TIME
	 P0 		 4 		 0 		 4
	 P1 		 4 		 4 		 8
	 P2 		 4 		 8 		 12
	 P3 		 4 		 12 		 16

Average Waiting Time : 6.000000
Average Turnaround Time : 10.000000
*/
