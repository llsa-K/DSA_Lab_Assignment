#include <stdio.h>

// Function to find and print leader elements in the array
void findLeaders(int arr[], int n) {
    int maxFromRight = arr[n - 1];
    int leaders[n];
    int leaderCount = 0;

    leaders[leaderCount++] = maxFromRight;

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxFromRight) {
            maxFromRight = arr[i];
            leaders[leaderCount++] = maxFromRight;
        }
    }

    // Print leaders in correct order
    printf("Leader elements are: ");
    for (int i = leaderCount - 1; i >= 0; i--) {
        printf("%d ", leaders[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findLeaders(arr, n);

    return 0;
}
