#include <stdio.h>

void firstFit(int holes[], int numHoles, int processes[], int numProcesses) {
    int i, j, totalFragmentation = 0;
    int sts[numProcesses];
    int allocatedHoles[numProcesses];

    for (i = 0; i < numProcesses; i++) {
        sts[i] = 0;
        for (j = 0; j < numHoles; j++) {
            if (processes[i] <= holes[j]) {
                sts[i] = 1;
                allocatedHoles[i] = holes[j];
                break;
            }
        }
    }
    for (i = 0; i < numProcesses; i++) 
        if (sts[i] == 1) 
            printf("Process %d of size %d allocated hole size: %d\n", i, processes[i], allocatedHoles[i]);
}

void sort(int array[], int n, int ascending) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if ((ascending && array[i] > array[j]) || (!ascending && array[i] < array[j])) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void bestFit(int holes[], int numHoles, int processes[], int numProcesses) {
    sort(holes, numHoles, 1);
    firstFit(holes, numHoles, processes, numProcesses);
}

void worstFit(int holes[], int numHoles, int processes[], int numProcesses) {
    sort(holes, numHoles, 0);
    firstFit(holes, numHoles, processes, numProcesses);
}

int main() {
    int numHoles, numProcesses, i, choice;
    printf("Enter number of holes and processes: ");
    scanf("%d %d", &numHoles, &numProcesses);

    int holes[numHoles], processes[numProcesses];
    printf("Enter hole sizes: ");
    for (i = 0; i < numHoles; i++) {
        scanf("%d", &holes[i]);
    }
    printf("Enter process sizes: ");
    for (i = 0; i < numProcesses; i++) {
        scanf("%d", &processes[i]);
    }

    do {
        printf("Select 1:First Fit 2:Worst Fit 3:Best Fit 0:Exit: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: firstFit(holes, numHoles, processes, numProcesses); break;
            case 2: worstFit(holes, numHoles, processes, numProcesses); break;
            case 3: bestFit(holes, numHoles, processes, numProcesses); break;
        }
    } while (choice != 0);

    return 0;
}
