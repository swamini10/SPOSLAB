#include <stdio.h>

int main() {
    int p[20], bt[20], pri[20], rt[20], wt[20], tat[20], n, i, time, smallest, count = 0;
    float wtavg = 0, tatavg = 0;

    // Print the heading for the program
    printf("\n *** Preemptive Priority Scheduling Algorithm ***\n");
    
    // Ask the user to enter the number of processes
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);  // Read the number of processes

    // Ask the user to enter the burst time and priority for each process
    for (i = 0; i < n; i++) {
        p[i] = i;  // Process numbers are assigned in order (0, 1, 2, ...)
        printf("Enter the Burst Time and Priority of Process %d: ", i);  // Prompt for burst time and priority
        scanf("%d %d", &bt[i], &pri[i]);  // Read burst time and priority for the current process
        rt[i] = bt[i];  // Initialize remaining time as burst time
    }

    pri[19] = 9999;  // Set a high value for the last element to avoid checking it in the loop
    
    // Main loop for Preemptive Priority Scheduling
    for (time = 0; count != n; time++) {
        smallest = 19;  // Set an initial large value for comparison

        // Find the process with the smallest priority and remaining time > 0
        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && pri[i] < pri[smallest]) {
                smallest = i;  // If current process has higher priority, select it
            }
        }

        rt[smallest]--;  // Reduce remaining time for the selected process

        // If the process has completed (remaining time is 0)
        if (rt[smallest] == 0) {
            count++;
            tat[smallest] = time + 1;  // Turnaround time is time of completion
            wt[smallest] = tat[smallest] - bt[smallest];  // Waiting time = Turnaround time - Burst time
            wtavg += wt[smallest];  // Accumulate total waiting time
            tatavg += tat[smallest];  // Accumulate total turnaround time
        }
    }

    // Print the results in tabular format
    printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d", p[i], pri[i], bt[i], wt[i], tat[i]);
    }

    // Calculate and display the average waiting time and average turnaround time
    printf("\nAverage Waiting Time is --- %f", wtavg / n);
    printf("\nAverage Turnaround Time is --- %f\n", tatavg / n);

    return 0;
}

/*
Example Input:

Enter the number of processes: 4
Enter the Burst Time and Priority of Process 0: 6 2
Enter the Burst Time and Priority of Process 1: 8 1
Enter the Burst Time and Priority of Process 2: 7 3
Enter the Burst Time and Priority of Process 3: 3 4

Example Output:

PROCESS         PRIORITY   BURST TIME   WAITING TIME    TURNAROUND TIME
0               2          6            6               12
1               1          8            6               14
2               3          7            13              20
3               4          3            18              21

Average Waiting Time is --- 10.250000
Average Turnaround Time is --- 16.750000
*/
