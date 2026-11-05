
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, position, value, found = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = malloc((n + 1) * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d array elements:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Display original array
    printf("\nOriginal array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Insert a value
    printf("\n\nEnter value to insert: ");
    scanf("%d", &value);

    printf("Enter position (1 to %d): ", n + 1);
    scanf("%d", &position);

    if (position < 1 || position > n + 1) {
        printf("Invalid position!\n");
    } else {
        for (i = n; i >= position; i--) {
            arr[i] = arr[i - 1];
        }

        arr[position - 1] = value;
        n++;

        printf("Array after insertion: ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }

    // Delete a value
    printf("\n\nEnter value to delete: ");
    scanf("%d", &value);

    found = 0;

    for (i = 0; i < n; i++) {
        if (arr[i] == value) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        n--;

        printf("Array after deletion: ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    } else {
        printf("Value not found in the array!\n");
    }

    free(arr);

    return 0;
}
