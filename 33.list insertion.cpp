#include <stdio.h>
#define MAX_SIZE 100
int main() {
    int arr[MAX_SIZE];
    int n, num, pos;
    printf("Name :G Venkata Chalapathi\nReg no :192211150");
    printf("Enter number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number to insert: ");
    scanf("%d", &num);

    printf("Enter the position (1 to %d) to insert: ", n + 1);
    scanf("%d", &pos);

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = num;
    n++;

    printf("List after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}