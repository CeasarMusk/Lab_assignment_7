#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n, int swaps[]);
void selectionSort(int arr[], int n, int swaps[]);

int main() {
    int a1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int a2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(a1) / sizeof(a1[0]);
    int n2 = sizeof(a2) / sizeof(a2[0]);

    int* bswaps1 = (int*)malloc(n1 * sizeof(int));
    int* bswaps2 = (int*)malloc(n2 * sizeof(int));

    int* sswaps1 = (int*)malloc(n1 * sizeof(int));
    int* sswaps2 = (int*)malloc(n2 * sizeof(int));

    printf("Bubble Sort:\n");
    printf("arr1:\n");
    bubbleSort(a1, n1, bswaps1);
    printf("\narr2:\n");
    bubbleSort(a2, n2, bswaps2);

    printf("\nSelection Sort:\n");
    printf("arr1:\n");
    selectionSort(a1, n1, sswaps1);
    printf("\narr2:\n");
    selectionSort(a2, n2, sswaps2);

    free(bswaps1);
    free(bswaps2);
    free(sswaps1);
    free(sswaps2);

    return 0;
}

void bubbleSort(int arr[], int n, int swaps[]) {
    int totalSwaps = 0;
    for (int i = 0; i < n; i++) {
        swaps[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swaps[arr[j]]++;
                totalSwaps++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d: # of times %d is swapped: %d\n", arr[i], arr[i], swaps[arr[i]]);
    }
    printf("total # of swaps: %d\n", totalSwaps);
}

void selectionSort(int arr[], int n, int swaps[]) {
    int totalSwaps = 0;
    for (int i = 0; i < n; i++) {
        swaps[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;

        swaps[arr[i]]++;
        totalSwaps++;
    }

    for (int i = 0; i < n; i++) {
        printf("%d: # of times %d is swapped: %d\n", arr[i], arr[i], swaps[arr[i]]);
    }
    printf("total # of swaps: %d\n", totalSwaps);
}