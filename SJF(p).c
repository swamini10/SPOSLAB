#include <stdio.h>

int main()
{
    int arrival_time[10], burst_time[10], temp[10];
    int i, smallest, count = 0, time, limit;
    double wait_time = 0, turnaround_time = 0, end;
    float average_waiting_time, average_turnaround_time;

    // Prompt user to enter the total number of processes
    printf("\nEnter the Total Number of Processes:");
    scanf("%d", &limit);  // Read the number of processes
    
    // Prompt user to enter arrival and burst times for each process
    printf("\nEnter Details of %d Processes:", limit);
    for (i = 0; i < limit; i++)
    {
        // Read arrival time and burst time for each process
        printf("\nEnter Arrival Time:");
        scanf("%d", &arrival_time[i]);
        printf("\nEnter Burst Time:");
        scanf("%d", &burst_time[i]);
        temp[i] = burst_time[i];  // Store the original burst time for later calculation of waiting time
    }
    
    // Set the last burst time to a large value to ensure it doesn't get selected in the loop
    burst_time[9] = 9999;
    
    // Start the time variable from 0 and iterate until all processes are executed
    for (time = 0; count != limit; time++)
    {
        smallest = 9;  // Initialize the smallest to a large value (out of range of processes)

        // Find the process that has arrived and has the smallest burst time
        for (i = 0; i < limit; i++)
        {
            // The process must have arrived (arrival_time[i] <= time) and should not be executed yet (burst_time[i] > 0)
            if (arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
            {
                smallest = i;  // Select the process with the smallest burst time
            }
        }
        
        // Decrease the burst time of the selected process (simulate the process running for one unit of time)
        burst_time[smallest]--;
        
        // If the selected process has finished execution (burst_time[i] == 0)
        if (burst_time[smallest] == 0)
        {
            count++;  // Increment the count of completed processes
            
            // Calculate the end time of the current process (time + 1 because we're working in time units)
            end = time + 1;
            
            // Calculate waiting time for the current process
            wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
            
            // Calculate turnaround time for the current process
            turnaround_time = turnaround_time + end - arrival_time[smallest];
        }
    }
    
    // Calculate the average waiting time and average turnaround time
    average_waiting_time = wait_time / limit;
    average_turnaround_time = turnaround_time / limit;

    // Print the average waiting time and average turnaround time
    printf("\n\nAverage Waiting Time:%lf", average_waiting_time);
    printf("\n\nAverage Turnaround Time:%lf", average_turnaround_time);

    return 0;
}

/*
Example Input:

Enter the Total Number of Processes: 3
Enter Details of 3 Processes:
Enter Arrival Time: 0
Enter Burst Time: 5
Enter Arrival Time: 1
Enter Burst Time: 3
Enter Arrival Time: 2
Enter Burst Time: 8

Example Output:

Average Waiting Time: 6.000000
Average Turnaround Time: 10.000000
*/
