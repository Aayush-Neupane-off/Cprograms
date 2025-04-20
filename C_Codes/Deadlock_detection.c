/*WAP to implement Bankers Algorithm for multiple type of resources to decide 
safe/unsafe state. */ 

#include <stdio.h>
#include <stdbool.h>

void calculateNeed(int P, int R, int need[P][R], int max[P][R], int allot[P][R]) {
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }
}

bool isSafe(int P, int R, int processes[], int avail[], int max[][R], int allot[][R]) {
    int need[P][R];
    calculateNeed(P, R, need, max, allot);

    bool finish[P];
    for (int i = 0; i < P; i++) {
        finish[i] = false;
    }

    int safeSeq[P];
    int work[R];
    for (int i = 0; i < R; i++) {
        work[i] = avail[i];
    }

    int count = 0;
    while (count < P) {
        bool found = false;
        for (int p = 0; p < P; p++) {
            if (!finish[p]) {
                int j;
                for (j = 0; j < R; j++) {
                    if (need[p][j] > work[j])
                        break;
                }
                if (j == R) {
                    for (int k = 0; k < R; k++) {
                        work[k] += allot[p][k];
                    }
                    safeSeq[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("System is not in safe state\n");
            return false;
        }
    }
    printf("System is in safe state\nSafe sequence is: ");
    for (int i = 0; i < P; i++) {
        printf("%d ", safeSeq[i]);
    }
    printf("\n");
    return true;
}

int main() {
    int P, R;
    printf("Enter the number of processes: ");
    scanf("%d", &P);
    printf("Enter the number of resources: ");
    scanf("%d", &R);

    int processes[P];
    for (int i = 0; i < P; i++) {
        processes[i] = i;
    }

    int avail[R];
    printf("Enter the available resources: ");
    for (int i = 0; i < R; i++) {
        scanf("%d", &avail[i]);
    }

    int max[P][R], allot[P][R];
    printf("Enter the maximum resources for each process: \n");
    for (int i = 0; i < P; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < R; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocated resources for each process: \n");
    for (int i = 0; i < P; i++) {
        printf("Process %d: ", i);
        for (int j = 0; j < R; j++) {
            scanf("%d", &allot[i][j]);
        }
    }

    isSafe(P, R, processes, avail, max, allot);

    return 0;
}

/*  WAP for deadlock detection in the system having multiple type of resources. The 
program should list the deadlocked process in case of deadlock detection results 
true) */


// #include <stdio.h>
// #include <stdbool.h>

// void calculateNeed(int P, int R, int need[P][R], int max[P][R], int allot[P][R]) {
//     for (int i = 0; i < P; i++) {
//         for (int j = 0; j < R; j++) {
//             need[i][j] = max[i][j] - allot[i][j];
//         }
//     }
// }

// bool deadlockDetection(int P, int R, int processes[], int avail[], int max[][R], int allot[][R]) {
//     int need[P][R];
//     calculateNeed(P, R, need, max, allot);

//     bool finish[P];
//     for (int i = 0; i < P; i++) {
//         finish[i] = false;
//     }

//     int work[R];
//     for (int i = 0; i < R; i++) {
//         work[i] = avail[i];
//     }

//     int count = 0;
//     while (count < P) {
//         bool found = false;
//         for (int p = 0; p < P; p++) {
//             if (!finish[p]) {
//                 int j;
//                 for (j = 0; j < R; j++) {
//                     if (need[p][j] > work[j])
//                         break;
//                 }
//                 if (j == R) {
//                     for (int k = 0; k < R; k++) {
//                         work[k] += allot[p][k];
//                     }
//                     finish[p] = true;
//                     found = true;
//                 }
//             }
//         }
//         if (!found) {
//             printf("System is in deadlock state\nDeadlocked processes: ");
//             for (int p = 0; p < P; p++) {
//                 if (!finish[p]) {
//                     printf("%d ", p);
//                 }
//             }
//             printf("\n");
//             return true;
//         }
//         count++;
//     }
//     printf("No deadlock detected\n");
//     return false;
// }

// int main() {
//     int P, R;
//     printf("Enter the number of processes: ");
//     scanf("%d", &P);
//     printf("Enter the number of resources: ");
//     scanf("%d", &R);

//     int processes[P];
//     for (int i = 0; i < P; i++) {
//         processes[i] = i;
//     }

//     int avail[R];
//     printf("Enter the available resources: ");
//     for (int i = 0; i < R; i++) {
//         scanf("%d", &avail[i]);
//     }

//     int max[P][R], allot[P][R];
//     printf("Enter the maximum resources for each process: \n");
//     for (int i = 0; i < P; i++) {
//         printf("Process %d: ", i);
//         for (int j = 0; j < R; j++) {
//             scanf("%d", &max[i][j]);
//         }
//     }

//     printf("Enter the allocated resources for each process: \n");
//     for (int i = 0; i < P; i++) {
//         printf("Process %d: ", i);
//         for (int j = 0; j < R; j++) {
//             scanf("%d", &allot[i][j]);
//         }
//     }

//     deadlockDetection(P, R, processes, avail, max, allot);

//     return 0;
// }
