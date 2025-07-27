#include <stdio.h>
#define MAX_SIZE 100

// Function declarations
void traverse(int arr[], int n);
int arrayLength(int n);
int search(int arr[], int n, int key);
int findMax(int arr[], int n);
int findMin(int arr[], int n);
int insert(int arr[], int *n, int pos, int val);
int delete(int arr[], int *n, int pos);
int linearSearch(int arr[], int n, int key);

int main() {
    int arr[MAX_SIZE], n, choice, pos, val, key, index;

    printf("Enter number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);
    if (n > MAX_SIZE) return printf("Size exceeds max limit!\n"), 1;

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    do {
        printf("\nMenu:\n");
        printf("1. Traverse\n2. Array Length\n3. Search\n4. Find Max\n");
        printf("5. Find Min\n6. Insert\n7. Delete\n8. Linear Search\n9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Array: "); traverse(arr, n); break;
            case 2:
                printf("Length: %d\n", arrayLength(n)); break;
            case 3:
                printf("Enter element to search: "); scanf("%d", &key);
                index = search(arr, n, key);
                printf(index != -1 ? "Found at index %d\n" : "Not found\n", index);
                break;
            case 4:
                printf("Max: %d\n", findMax(arr, n)); break;
            case 5:
                printf("Min: %d\n", findMin(arr, n)); break;
            case 6:
                printf("Enter position (0 to %d): ", n); scanf("%d", &pos);
                if (pos < 0 || pos > n) { printf("Invalid position!\n"); break; }
                printf("Enter value: "); scanf("%d", &val);
                insert(arr, &n, pos, val) ? printf("Inserted.\n") : printf("Insertion failed.\n");
                break;
            case 7:
                printf("Enter position (0 to %d): ", n - 1); scanf("%d", &pos);
                if (pos < 0 || pos >= n) { printf("Invalid position!\n"); break; }
                delete(arr, &n, pos) ? printf("Deleted.\n") : printf("Deletion failed.\n");
                break;
            case 8:
                printf("Enter element to search: "); scanf("%d", &key);
                index = linearSearch(arr, n, key);
                printf(index != -1 ? "Found at index %d\n" : "Not found\n", index);
                break;
            case 9:
                printf("Exiting...\n"); break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 9);

    return 0;
}

// Traverse array
void traverse(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Return length
int arrayLength(int n) { return n; }

// Search element (returns index or -1)
int search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) if (arr[i] == key) return i;
    return -1;
}

// Find maximum value
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];
    return max;
}

// Find minimum value
int findMin(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] < min) min = arr[i];
    return min;
}

// Insert value at position
int insert(int arr[], int *n, int pos, int val) {
    if (*n >= MAX_SIZE) return 0;
    for (int i = *n; i > pos; i--) arr[i] = arr[i - 1];
    arr[pos] = val;
    (*n)++;
    return 1;
}

// Delete value from position
int delete(int arr[], int *n, int pos) {
    if (*n <= 0) return 0;
    for (int i = pos; i < *n - 1; i++) arr[i] = arr[i + 1];
    (*n)--;
    return 1;
}

// Linear search
int linearSearch(int arr[], int n, int key) {
    return search(arr, n, key);
}
