#include <stdio.h>

int search(int r, int fa, int p[]) {
    for (int i = 0; i < fa; i++) {
        if (p[i] == r) {
            return i;
        }
    }
    return -1;
}

int fifo(int n, int rs[], int fa) {
    int p[fa], cn = 0, l = 0;
    for (int i = 0; i < fa; i++) {
        p[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        if (search(rs[i], fa, p) != -1) {
            // Page is already in frame, do nothing
        } else {
            int k = search(-1, fa, p);
            if (k == -1) {
                p[l % fa] = rs[i];
                l++;
            } else {
                p[k] = rs[i];
            }
            cn++;
        }
        printf("Page numbers after reference %d: ", rs[i]);
        for (int j = 0; j < fa; j++)
            printf("%d ", p[j]);
        printf("\n");
    }
    return cn;
}

int optimal(int n, int rs[], int fa) {
    int p[fa], cn = 0;
    for (int i = 0; i < fa; i++) {
        p[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        if (search(rs[i], fa, p) != -1) {
            // Page is already in frame, do nothing
        } else {
            int maxDist = -1, idx = -1;
            for (int j = 0; j < fa; j++) {
                int found = 0;
                for (int k = i + 1; k < n; k++) {
                    if (rs[k] == p[j]) {
                        found = 1;
                        if (k > maxDist) {
                            maxDist = k;
                            idx = j;
                        }
                        break;
                    }
                }
                if (!found) {
                    idx = j;
                    break;
                }
            }
            p[idx] = rs[i];
            cn++;
        }
        printf("Page numbers after reference %d: ", rs[i]);
        for (int j = 0; j < fa; j++)
            printf("%d ", p[j]);
        printf("\n");
    }
    return cn;
}

int lru(int n, int rs[], int fa) {
    int p[fa], cn = 0;
    for (int i = 0; i < fa; i++) {
        p[i] = -1;
    }
    int lru[fa];
    for (int i = 0; i < fa; i++) {
        lru[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int index = search(rs[i], fa, p);
        if (index != -1) {
            lru[index] = i;
        } else {
            int minIndex = 0;
            for (int j = 1; j < fa; j++) {
                if (lru[j] < lru[minIndex]) {
                    minIndex = j;
                }
            }
            p[minIndex] = rs[i];
            lru[minIndex] = i;
            cn++;
        }
        printf("Page numbers after reference %d: ", rs[i]);
        for (int j = 0; j < fa; j++)
            printf("%d ", p[j]);
        printf("\n");
    }
    return cn;
}

int lfu(int n, int rs[], int fa) {
    int p[fa], cn = 0, freq[fa], insertOrder[fa], insertCounter = 0;
    for (int i = 0; i < fa; i++) {
        p[i] = -1;
        freq[i] = 0;
        insertOrder[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int index = search(rs[i], fa, p);
        if (index != -1) {
            freq[index]++;
        } else {
            int minIndex = 0;
            for (int j = 1; j < fa; j++) {
                if (freq[j] < freq[minIndex]) {
                    minIndex = j;
                } else if (freq[j] == freq[minIndex] && insertOrder[j] < insertOrder[minIndex]) {
                    minIndex = j;
                }
            }
            p[minIndex] = rs[i];
            freq[minIndex] = 1;
            insertOrder[minIndex] = insertCounter++;
            cn++;
        }
        printf("Page numbers after reference %d: ", rs[i]);
        for (int j = 0; j < fa; j++)
            printf("%d ", p[j]);
        printf("\n");
    }
    return cn;
}

int main() {
    int rs[100], fa, n, x;
    printf("Enter number of reference strings: ");
    scanf("%d", &n);
    printf("Enter reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }
    printf("Enter number of frames allocated: ");
    scanf("%d", &fa);
    printf("1: FIFO 2: Optimal 3: LRU 4: LFU\n");
    do {
        scanf("%d", &x);
        switch (x) {
            case 0: break;
            case 1:printf("Page faults using FIFO: %d\n", fifo(n, rs, fa));break;
            case 2:printf("Page faults using Optimal: %d\n", optimal(n, rs, fa));break;
            case 3:printf("Page faults using LRU: %d\n", lru(n, rs, fa));break;
            case 4:printf("Page faults using LFU: %d\n", lfu(n, rs, fa));
        }
        printf("Continue (0/1)? ");
        scanf("%d", &x);
    } while (x != 0);
    return 0;
}
