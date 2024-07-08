#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct file {
    char fname[10];
    int status, start, noall, fsize, next, index[10];
};

void sequential(int ms, int bs, int nb) {
    int fs, ch, i, start, j, flag;
    char fn[10];
    struct file seq[nb];
    for(i = 0; i < nb; i++) {
        seq[i].status = 0;
    }
    do {
        printf("1: Create file\n2: Display files\n3: Search file\n4: Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter file name, file size, starting position \n");
                scanf("%s%d%d", fn, &fs, &start);
                seq[start].status = 1;
                seq[start].noall = (fs + bs - 1) / bs;
                seq[start].fsize = fs;
                strcpy(seq[start].fname, fn);
                seq[start].start = start;
                printf("File created\n");
                break;
            case 2:
                printf("Fname\tFsize\tReqno\tStart\tAllocated\n");
                for (i = 0; i < nb; i++)
                    if (seq[i].status == 1) {
                        printf("%s\t%d\t%d\t%d\t", seq[i].fname, seq[i].fsize, seq[i].noall, seq[i].start);
                        for(j = i; j < seq[i].noall + seq[i].start; j++)
                            printf("%d ", j);
                        printf("\n");
                    }
                break;
                 case 3:
                flag = 0;
                printf("Enter file name to search: ");
                scanf("%s", fn);
                for (i = 0; i < nb; i++)
                    if (seq[i].status == 1 && strcmp(seq[i].fname, fn) == 0) {
                        printf("File found\n");
                        flag = 1;
                    }
                if (flag == 0)
                    printf("File not found\n");
                break;
        }
    } while(ch != 4);
}

void linkedlist(int ms, int bs, int nb) {
    int fs, n, ch, i, start, j, flag, all[10];
    char fn[10];
    struct file ll[nb];
    for(i = 0; i < nb; i++) {
        ll[i].status = 0;
    }
    do {
        printf("1: Create file\n2: Display files\n3: Search file\n4: Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter file name, file size\n");
                scanf("%s%d", fn, &fs);
                n = (fs + bs - 1) / bs;
                printf("Enter file locations: ");
                for(i = 0; i < n; i++)
                    scanf("%d", &all[i]);
                start = all[0];
                ll[start].status = 1;
                ll[start].noall = n;
                ll[start].fsize = fs;
                strcpy(ll[start].fname, fn);
                ll[start].start = start;
                for(i = 0; i < n - 1; i++)
                    ll[all[i]].next = all[i + 1];
                ll[all[i]].next = -1;
                printf("File created\n");
                break;
 case 2:
                printf("Fname\tFsize\tReqno\tStart\tAllocated\n");
                for (i = 0; i < nb; i++)
                    if (ll[i].status == 1) {
                        printf("%s\t%d\t%d\t%d\t", ll[i].fname, ll[i].fsize, ll[i].noall, ll[i].start);
                        j = i;
                        while(j != -1) {
                            printf(" -> %d", j);
                            j = ll[j].next;
                        }
                        printf("\n");
                      }
                break;
            case 3:
                flag = 0;
                printf("Enter file name to search: ");
                scanf("%s", fn);
                for (i = 0; i < nb; i++)
                    if (ll[i].status == 1 && strcmp(ll[i].fname, fn) == 0) {
                        printf("File found\n");
                        flag = 1;
                    }
                if (flag == 0)
                    printf("File not found\n");
                break;
        }
    } while(ch != 4);
}

void Indexed(int ms, int bs, int nb) {
    int fs, n, ch, i, start, j, flag, all[10],k;
    char fn[10];
    struct file ind[nb];
    for(i = 0; i < nb; i++) {
        ind[i].status = 0;
    }
    do {
        printf("1: Create file\n2: Display files\n3: Search file\n4: Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter file name, file size\n");
                scanf("%s%d", fn, &fs);
                printf("Enter file locations: ");
                n = (fs + bs - 1) / bs;
                for(i = 0; i < n; i++)
                    scanf("%d", &all[i]);
                printf("Enter index locations: ");
                k = (n + bs - 1) / bs;
                for(i = 0; i < k; i++)
                    scanf("%d", &ind[all[0]].index[i]);
                start = all[0];
                ind[start].status = 1;
                ind[start].noall = n;
                ind[start].fsize = fs;
                strcpy(ind[start].fname, fn);
                ind[start].start = start;
                for(i = 0; i < n - 1; i++)
                    ind[all[i]].next = all[i + 1];
                ind[all[i]].next = -1;
                printf("File created\n");
                break;
            case 2:
                printf("Fname\tFsize\tReqno\tStart\tIndex\tAllocated\n");
                for (i = 0; i < nb; i++)
                    if (ind[i].status == 1) {
                        printf("%s\t%d\t%d\t%d\t", ind[i].fname, ind[i].fsize, ind[i].noall, ind[i].start);
                        for(int l=0;l<k;l++)
                                printf("%d\t",ind[i].index[l]);
                        j = i;
                        while(j != -1) {
                            printf(" , %d", j);
                            j = ind[j].next;
                        }
                        printf("\n");
                    }
                break;
            case 3:
                flag = 0;
                printf("Enter file name to search: ");
                scanf("%s", fn);
                for (i = 0; i < nb; i++)
                    if (ind[i].status == 1 && strcmp(ind[i].fname, fn) == 0) {
                        printf("File found\n");
                        flag = 1;
                    }
                if (flag == 0)
                    printf("File not found\n");
                break;
        }
    } while(ch != 4);
}

int main() {
    int i, ms, bs, nb;
    printf("Enter memory size and block size\n");
    scanf("%d%d", &ms, &bs);
    nb = ms / bs;
    do {
        printf("1: Sequential  2: Linked list  3: Indexed  4: Exit\n");
        scanf("%d", &i);
        switch(i) {
            case 1: sequential(ms, bs, nb); break;
            case 2: linkedlist(ms, bs-1, nb); break;
            case 3: Indexed(ms, bs, nb); break;
            case 4: break;
        }
    } while(i != 4);
    return 0;
}

