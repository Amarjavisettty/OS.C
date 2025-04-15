#include <stdio.h>

int main() {
    int ms, bs, p[10], i, temp, n = 0;

    printf("Enter total memory available (in Bytes): ");
    scanf("%d", &ms);
    temp = ms;

    while(temp > 0) {
        printf("Enter memory required for process %d: ", n + 1);
        scanf("%d", &p[n]);

        if(p[n] <= temp) {
            printf("Process %d is allocated\n", n + 1);
            temp -= p[n];
            n++;
        } else {
            printf("Memory is full, cannot allocate process %d\n", n + 1);
            break;
        }
    }

    printf("\nTotal Memory Allocated: %d\n", ms - temp);
    printf("Total Memory Left: %d\n", temp);

    return 0;
}
