#include<stdio.h>
#include<stdlib.h>

void frameallocation(int fs, int nf, int method) {  
    int i, nfp[10], k, n, mframes, total = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i=0;i<n;i++) {
        printf("Enter process %d size: ", i);
        scanf("%d", &nfp[i]);
        k = nfp[i]/fs;
        total += k;
        printf("Number of frames required by %d process: %d\n", i, k);
    }
    switch(method){
    case 1: printf("Enter minimum number of frames: ");
            scanf("%d", &mframes); 
            break;
    case 2: mframes = fs / n; break;
    case 3: for(i=0;i<n;i++) {
                mframes = nfp[i] / total;
                printf("P%d\t%d\t%d\t\t%d\n", i, nfp[i], nfp[i]/fs, mframes);
                nf -= mframes;
                }
            printf("Left over frames: %d\n", nf);
            return;
    }
    printf("Process\tPsize\tReq frames\tAllocated frames\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t\t%d\n", i, nfp[i], nfp[i]/fs, mframes);
    printf("Left over frames: %d\n", nf - mframes * n);
}
int main() {
 int ms, fs, nf, n, k;
 printf("Enter memory size, frame size\n");
 scanf("%d%d", &ms, &fs);
 nf = ms/fs;
 printf("Number of frames: %d\n", nf);
 do {
  printf("1: Minimum number of frames\n2: Equal Allocation\n3: Proportional Allocation\n4: Exit\n");
  scanf("%d", &k);
  if(k==4)break;
  frameallocation(fs, nf, k);
}while(k!=4);
 return 0;
}
