#include <stdio.h>
#include <stdbool.h>

#define MAX_ITEMS 100
#define MAX_CONTAINERS 100

void loadContainers(int items[], int n, int containers[], int m) {
    int containerIndex = 0;
    containers[containerIndex] = 0;
    for (int i = 0; i < n; i++) {
        if (containers[containerIndex] + items[i] <= m) {
            containers[containerIndex] += items[i];
        } else {
            containerIndex++;
            containers[containerIndex] = items[i];
        }
    }
}

void printContainers(int containers[], int numContainers) {
    printf("Container Loading Result:\n");
    for (int i = 0; i <= numContainers; i++) {
        printf("Container %d: %d units\n", i + 1, containers[i]);
    }
}

int main() {
    int items[MAX_ITEMS];
    int containers[MAX_CONTAINERS];
    int n, m;
    printf("Name :G Venkata Chalapathi\nReg no :192211150");
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the sizes of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i]);
    }

    printf("Enter the maximum capacity of each container: ");
    scanf("%d", &m);

    loadContainers(items, n, containers, m);

    printContainers(containers, n);

    return 0;
}