#include <stdio.h>

int main() {
    int mem, bsize, n, p[10], frag[10], i;

    printf("Enter total memory available (in Bytes): ");
    scanf("%d", &mem);
    printf("Enter block size (in Bytes): ");
    scanf("%d", &bsize);

    n = mem / bsize;
    printf("Number of blocks available: %d\n", n);

    for(i = 0; i < n; i++) {
        printf("Enter size of process %d: ", i + 1);
        scanf("%d", &p[i]);

        if(p[i] > bsize) {
            printf("Process can't be allocated\n");
            p[i] = -1;
        } else {
            frag[i] = bsize - p[i];
        }
    }

    printf("Block\tProcess Size\tFragment\n");
    for(i = 0; i < n; i++) {
        if(p[i] != -1)
            printf("%d\t%d\t\t%d\n", i+1, p[i], frag[i]);
    }

    return 0;
}
