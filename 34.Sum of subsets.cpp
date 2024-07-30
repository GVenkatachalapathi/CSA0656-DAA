#include <stdio.h>
#define MAX 20
int set[MAX];
int subset[MAX];
int n, targetSum;
void printSubset(int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}
void sumOfSubsets(int index, int currentSum, int remainingSum) {
    if (currentSum == targetSum) {
        printSubset(index);
        return;
    }

    if (index == n || currentSum + set[index] > targetSum) {
        return;
    }

    for (int i = index; i < n; i++) {
        if (currentSum + set[i] <= targetSum) {
            subset[index] = set[i];
            sumOfSubsets(index + 1, currentSum + set[i], remainingSum - set[i]);
        }
    }
}

int main() {
    int totalSum = 0;
    printf("Name :G Venkata Chalapathi\nReg no :192211150");
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
        totalSum += set[i];
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    if (totalSum < targetSum) {
        printf("No subset with the given sum exists.\n");
        return 1;
    }

    printf("Subsets with the sum %d are:\n", targetSum);
    sumOfSubsets(0, 0, totalSum);

    return 0;
}