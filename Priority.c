#include <stdio.h>
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int arrivalTime[n], burstTime[n], priority[n];
    int waitingTime[n], turnaroundTime[n];
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        printf("\nEnter Arrival Time, Burst Time, and Priority for Process %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arrivalTime[i]);
        printf("Burst Time: ");
        scanf("%d", &burstTime[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] > priority[j]) {
                int temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;
                temp = arrivalTime[i];
                arrivalTime[i] = arrivalTime[j];
                arrivalTime[j] = temp;
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
            }
        }
    }
    waitingTime[0] = 0;  
    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
    }
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrivalTime[i], burstTime[i], priority[i], waitingTime[i], turnaroundTime[i]);
    }
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

Enter Arrival Time, Burst Time, and Priority for Process 1
Arrival Time: 4
Burst Time: 5
Priority: 1

Enter Arrival Time, Burst Time, and Priority for Process 2
Arrival Time: 3
Burst Time: 6
Priority: 2

Enter Arrival Time, Burst Time, and Priority for Process 3
Arrival Time: 2
Burst Time: 7
Priority: 3

Enter Arrival Time, Burst Time, and Priority for Process 4
Arrival Time: 1
Burst Time: 8
Priority: 4

Enter Arrival Time, Burst Time, and Priority for Process 5
Arrival Time: 0
Burst Time: 9
Priority: 5

Process	Arrival Time	Burst Time	Priority	Waiting Time	Turnaround Time
1	4		5		1		0		5
2	3		6		2		5		11
3	2		7		3		11		18
4	1		8		4		18		26
5	0		9		5		26		35

Average Waiting Time: 12.00
Average Turnaround Time: 19.00
