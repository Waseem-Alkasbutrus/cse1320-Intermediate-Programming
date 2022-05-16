/*
 * Implementation of selection sort which sorts an integer array
 * in ascending order.
 */

void selection_sort(int arr[], int size) {
    // sort array
    for (int i = 0; i < size; i++) {
        int min_j = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_j]) {
                min_j = j;
            }
        }

        // Swap values
        if (min_j != i) {
            int temp = arr[i];
            arr[i] = arr[min_j];
            arr[min_j] = temp;
        }
    }
}
