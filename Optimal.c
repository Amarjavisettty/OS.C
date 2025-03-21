#include<stdio.h>
int main()
{
    int i, j, k, min, rs[25], m[10], n, f, pf = 0;
    int next_use[10];
    printf("Enter the length of reference string -- ");
    scanf("%d", &n);
    printf("Enter the reference string -- ");
    for(i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }
    printf("Enter the number of frames -- ");
    scanf("%d", &f);
    for(i = 0; i < f; i++) {
        m[i] = -1;
    }
    printf("\nThe Page Replacement process is -- \n");
    for(i = 0; i < n; i++) {
        int page_found = 0;
        for(j = 0; j < f; j++) {
            if(m[j] == rs[i]) {
                page_found = 1;
                break;
            }
        }
        if(page_found == 0) {
            pf++;

            if(i < f) {
                m[i] = rs[i];
            } else {
                for(j = 0; j < f; j++) {
                    next_use[j] = -1;
                    for(k = i + 1; k < n; k++) {
                        if(rs[k] == m[j]) {
                            next_use[j] = k;
                            break;
                        }
                    }
                }
                min = 0;
                for(j = 1; j < f; j++) {
                    if(next_use[min] == -1 || (next_use[j] != -1 && next_use[j] > next_use[min])) {
                        min = j;
                    }
                }
                m[min] = rs[i];
            }
        }
        for(j = 0; j < f; j++) {
            printf("%d\t", m[j]);
        }
        if(page_found == 0) {
            printf("PF No. -- %d", pf);
        }
        printf("\n");
    }
    printf("\nThe number of page faults using Optimal are %d", pf);
    return 0;
}
output
Enter the length of reference string -- 20
Enter the reference string -- 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
Enter the number of frames -- 3

The Page Replacement process is -- 
7	-1	-1	PF No. -- 1
7	0	-1	PF No. -- 2
7	0	1	PF No. -- 3
2	0	1	PF No. -- 4
2	0	1	
2	0	3	PF No. -- 5
2	0	3	
2	4	3	PF No. -- 6
2	4	3	
2	4	3	
0	4	3	PF No. -- 7
0	4	3	
2	4	3	PF No. -- 8
1	4	3	PF No. -- 9
2	4	3	PF No. -- 10
2	4	0	PF No. -- 11
2	4	1	PF No. -- 12
2	4	7	PF No. -- 13
2	4	0	PF No. -- 14
2	4	1	PF No. -- 15

The number of page faults using Optimal are 15

