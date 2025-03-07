#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 4 // Number of tasks (or workers)

void printSolution(int assignment[N]) {
    printf("Assigned tasks to workers with minimum cost:\n");
    for (int i = 0; i < N; i++) {
        printf("Worker %d -> Task %d\n", i, assignment[i]);
    }
    printf("\n");
}

void branchAndBoundUtil(int cost[N][N], int assignment[N], bool assigned[N],
                        int worker, int task, int currentCost, int *minCost);

void branchAndBound(int cost[N][N]) {
    int assignment[N];
    bool assigned[N];
    int minCost = INT_MAX;

    for (int i = 0; i < N; i++) {
        assigned[i] = false;
    }

    branchAndBoundUtil(cost, assignment, assigned, 0, 0, 0, &minCost);

    printSolution(assignment);
    printf("Minimum cost: %d\n", minCost);
}

void branchAndBoundUtil(int cost[N][N], int assignment[N], bool assigned[N],
                        int worker, int task, int currentCost, int *minCost) {
    if (worker == N) {
        if (currentCost < *minCost) {
            *minCost = currentCost;
            for (int i = 0; i < N; i++) {
                assignment[i] = assigned[i];
            }
        }
        return;
    }

    if (currentCost >= *minCost) {
        return;
    }

    for (int j = 0; j < N; j++) {
        if (!assigned[j]) {
            assigned[j] = true;
            assignment[worker] = j;
            branchAndBoundUtil(cost, assignment, assigned, worker + 1, j,
                               currentCost + cost[worker][j], minCost);
            assigned[j] = false;
        }
    }
}

int main() {
    printf("Name :G Venkata Chalapathi\nReg no :192211150");
    int cost[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    branchAndBound(cost);

    return 0;
}