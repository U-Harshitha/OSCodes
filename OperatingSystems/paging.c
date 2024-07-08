#include <stdio.h>
#include <stdlib.h>

int main() {
    int ms, fs, nf, n, pn, page, offset;
    printf("Enter memory size, frame size\n");
    scanf("%d%d", &ms, &fs);
    nf = ms / fs;
    printf("Number of frames: %d\nEnter number of processes: ", nf);
    scanf("%d", &n);

    int process[n][10], i, j, nfp[10], k;
    for (i = 0; i < n; i++) {
        printf("Enter process %d size: ", i);
        scanf("%d", &nfp[i]);

        int framesRequired = nfp[i] / fs;
        printf("Number of frames required by process %d: %d\n", i, framesRequired);
        printf("Enter frames of process %d: ", i);
        
        for (j = 0; j < framesRequired; j++) {
            scanf("%d", &process[i][j]);
        }
    }
    do {
        printf("Enter logical address (process no, page, offset)\n");
        scanf("%d%d%d", &pn, &page, &offset);

        printf("Physical address: %d\n", process[pn][page] * fs + offset);
        printf("(0 to continue / 1 to exit)");
        scanf("%d", &k);
    } while (k != 1);

    return 0;
}
