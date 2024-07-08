#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fcfs(int nReq, int requests[], int start) {
    int tot = abs(start - requests[0]);
    printf("Request\tHead movement\tTotal moves\n");
    printf("%d\t%d-%d\t\t%d\n", requests[0], start, requests[0], tot);
    for (int i = 1; i < nReq; i++) {
        tot += abs(requests[i] - requests[i - 1]);
        printf("%d\t%d-%d\t\t%d\n", requests[i], requests[i - 1], requests[i], abs(requests[i] - requests[i - 1]));
    }
    printf("Total number of moves: %d\n", tot);
}

void sstf(int nReq, int requests[], int start) {
    int tot = 0, curr = start, closestIndex, closestDistance;
    int visited[100] = {0};

    printf("Request\tHead movement\tTotal moves\n");
    for (int i = 0; i < nReq; i++) {
        closestDistance = INT_MAX;
        for (int j = 0; j < nReq; j++) {
            if (!visited[j] && abs(requests[j] - curr) < closestDistance) {
                closestIndex = j;
                closestDistance = abs(requests[j] - curr);
            }
        }
        visited[closestIndex] = 1;
        tot += closestDistance;
        printf("%d\t%d-%d\t\t%d\n", requests[closestIndex], curr, requests[closestIndex], closestDistance);
        curr = requests[closestIndex];
    }
    printf("Total number of moves: %d\n", tot);
}

int mvReq(int requests[], int start, int end, int increment) {
    int tot = 0;
    for (int i = start; i != end; i += increment) {
        tot += abs(requests[i + increment] - requests[i]);
        printf("%d\t%d-%d\t\t%d\n", requests[i + increment], requests[i], requests[i + increment], abs(requests[i + increment] - requests[i]));
    }
    return tot;
}

void scan(int nCyl, int nReq, int requests[], int strt, int start, int end, int isCScan) {
    int tot = 0, dir;

    do {
        printf("1: Towards right  2: Towards left  3: Exit\n");
        scanf("%d", &dir);
        if (dir == 1 || dir == 2) {
            printf("Request\tHead movement\tTotal moves\n");
            tot = (dir == 1) ? mvReq(requests, strt, end - 1, 1) : mvReq(requests, strt, start, -1);
            if (isCScan) {
                printf("%d\t%d-%d\t\t%d\n", (dir == 1) ? requests[0] : requests[nReq - 1], (dir == 1) ? requests[nReq - 1] : requests[0], (dir == 1) ? requests[0] : requests[nReq - 1], abs((dir == 1) ? requests[nReq - 1] - requests[0] : requests[0] - requests[nReq - 1]));
                tot += abs((dir == 1) ? requests[nReq - 1] - requests[0] : requests[0] - requests[nReq - 1]);
                tot += (dir == 1) ? mvReq(requests, 0, strt - 1, 1) : mvReq(requests, nReq - 1, strt + 1, -1);
            }
            printf("Total number of moves: %d\n", tot);
        }
    } while (dir != 3);
}

int main() {
    int nCyl, nReq, start, q[100], qsstf[100], qscan[100], strt;
    printf("Enter number of cylinders: ");
    scanf("%d", &nCyl);
    printf("Enter queue length: ");
    scanf("%d", &nReq);
    printf("Enter queue requests: ");
    for (int i = 0; i < nReq; i++) {
        scanf("%d", &q[i]);
        qsstf[i] = q[i];
        qscan[i] = q[i];
    }
    printf("Enter starting head point: ");
    scanf("%d", &start);

    qscan[nReq] = nCyl - 1;
    qscan[nReq + 1] = 0;
    qscan[nReq + 2] = start;
    int nSc = nReq + 3;
    for (int i = 0; i < nSc - 1; i++) {
        for (int j = 0; j < nSc - i - 1; j++) {
            if (qscan[j] > qscan[j + 1]) {
                int temp = qscan[j];
                qscan[j] = qscan[j + 1];
                qscan[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < nSc; i++) {
        if (qscan[i] == start) {
            strt = i;
            break;
        }
    }

    printf("1: FCFS  2: SSTF  3: SCAN  4: C-SCAN  5: LOOK  6: Exit\n");
    int choice;
    do {
        scanf("%d", &choice);
        switch (choice) {
            case 1: fcfs(nReq, q, start); break;
            case 2: sstf(nReq, qsstf, start); break;
            case 3: scan(nCyl, nSc, qscan, strt, 0, nSc, 0); break;
            case 4: scan(nCyl, nSc, qscan, strt, 0, nSc, 1); break;
            case 5: scan(nCyl, nSc, qscan, strt, 1, nSc - 1, 0);
                break;
            case 6:
                break;
        }
    } while (choice != 6);

    return 0;
}
