#include <stdio.h>
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int burstTime[n], waitingTime[n];
    int totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        printf("\nEnter Burst Time for Process %d\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &burstTime[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (burstTime[i] > burstTime[j]) { 
                int temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;
            }
        }
    }
    waitingTime[0] = 0;
    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i-1] + burstTime[i-1];
    }
    printf("\nProcess\tBurst Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", i + 1, burstTime[i], waitingTime[i]);
    }
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
    }
    printf("\nAverage Waiting Time: %.2f", (float)totalWaitingTime / n);
    return 0;
}
output
Enter number of processes: 3

Enter Burst Time for Process 1
Burst Time: 4

Enter Burst Time for Process 2
Burst Time: 3

Enter Burst Time for Process 3
Burst Time: 2

Process	Burst Time	Waiting Time
1	2		0
2	3		2
3	4		5

Average Waiting Time: 2.33
