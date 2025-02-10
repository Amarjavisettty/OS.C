#include <stdio.h>
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int arrivalTime[n], burstTime[n], waitingTime[n], turnaroundTime[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter Arrival Time and Burst Time for Process %d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &arrivalTime[i]);
        printf("Burst Time: ");
        scanf("%d", &burstTime[i]);
    }
    waitingTime[0] = 0; 
    for (int i = 1; i < n; i++) {
        waitingTime[i] = burstTime[i-1] + waitingTime[i-1];
    }
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
    }
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, arrivalTime[i], burstTime[i], waitingTime[i], turnaroundTime[i]);
    }
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }
    printf("\nAverage Waiting Time: %.2f", (float)totalWaitingTime / n);
    printf("\nAverage Turnaround Time: %.2f", (float)totalTurnaroundTime / n);
    
    return 0;
}
output
Enter number of processes: 5

Enter Arrival Time and Burst Time for Process 1
Arrival Time: 4
Burst Time: 5

Enter Arrival Time and Burst Time for Process 2
Arrival Time: 3
Burst Time: 6

Enter Arrival Time and Burst Time for Process 3
Arrival Time: 2
Burst Time: 7

Enter Arrival Time and Burst Time for Process 4
Arrival Time: 1
Burst Time: 8

Enter Arrival Time and Burst Time for Process 5
Arrival Time: 0
Burst Time: 0

Process	Arrival Time	Burst Time	Waiting Time	Turnaround Time
1	4		5		0		5
2	3		6		5		11
3	2		7		11		18
4	1		8		18		26
5	0		0		26		26

Average Waiting Time: 12.00
Average Turnaround Time: 17.20
