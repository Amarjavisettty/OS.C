#include <stdio.h>
#define MAX 10
struct Process {
    int pid;  
    int bt;   
    int wt;   
    int tat; 
};
void roundRobin(struct Process proc[], int n, int quantum) {
    int remainingTime[n];
    for (int i = 0; i < n; i++) {
        remainingTime[i] = proc[i].bt;
        proc[i].wt = 0;
    }
    int time = 0;
    int done = 0;
    while (done < n) {
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                if (remainingTime[i] <= quantum) {
                    time += remainingTime[i];
                    proc[i].wt = time - proc[i].bt;  
                    remainingTime[i] = 0;
                    done++;
                } else {
                    remainingTime[i] -= quantum;
                    time += quantum;
                }
            }
        }
    }
}
void calculateAverageTime(struct Process proc[], int n) {
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += proc[i].wt;
    }
    printf("\nAverage waiting time: %.2f\n", (float)total_wt / n);
}
int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process proc[MAX];
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter burst time for process %d: ", proc[i].pid);
        scanf("%d", &proc[i].bt);
    }
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    roundRobin(proc, n, quantum);
    calculateAverageTime(proc, n);
    return 0;
}
output
Enter number of processes: 3
Enter burst time for process 1: 4
Enter burst time for process 2: 5
Enter burst time for process 3: 6
Enter time quantum: 4

Average waiting time: 5.67
