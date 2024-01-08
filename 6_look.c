#include <stdio.h>
#include <stdlib.h>

int compare_function(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int i, n, TotalHeadMovement = 0, initial, size, move;

    printf("Enter the number of Requests\n");
    scanf("%d", &n);

    int requests[n];
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    printf("Enter initial head position\n");
    scanf("%d", &initial);

    printf("Enter total disk size\n");
    scanf("%d", &size);

    size -= 1; // since size is calculated from 0-199 not 1-200

    qsort(requests, n, sizeof(int), compare_function); // sorts the requests array in ascending order


    // Scan to the right)
    for (i = 0; i < n; i++) {
        if (requests[i] >= initial) {
            TotalHeadMovement += abs(requests[i] - initial);
            initial = requests[i];
        }
    }

    // Scan to the left)
    for (i = n - 1; i >= 0; i--) {
        if (requests[i] < initial) {
            TotalHeadMovement += abs(requests[i] - initial);
            initial = requests[i];
        }
    }

    printf("\nTotal Head Movement: %d\n", TotalHeadMovement);

    return 0;
}
