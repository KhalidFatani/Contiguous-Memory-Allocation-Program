#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t lock;
pthread_cond_t cond;

// Define sorted array
int arr[] = {7, 12, 19, 3, 18, 4, 2, 6, 15, 8};
int arr_size = sizeof(arr) / sizeof(arr[0]);
// Arrays to hold the two halves and the final sorted array
int first[5];
int half[5];
int sort[10];
int counter = 0;

// Function declarations
void *SortArrays(void *x);
void *fullSort(void *x);

// Function to sort the final array
void *fullSort(void *x) {
    int *num = (int *)x;
    for (int i = 0; i < arr_size; i++) {
        int j;
        int temp = num[i];
        for (j = i - 1; j >= 0; j--) {
            if (num[j] > temp) {
                num[j + 1] = num[j];
            } else {
                break;
            }
        }
        num[j + 1] = temp;
    }
    return NULL;
}

// Function to sort one half of the array
void *SortArrays(void *x) {
    int *num = (int *)x;
    int size = arr_size / 2;
    for (int i = 0; i < size; i++) {
        int j;
        int temp = num[i];
        for (j = i - 1; j >= 0; j--) {
            if (num[j] > temp) {
                num[j + 1] = num[j];
            } else {
                break;
            }
        }
        num[j + 1] = temp;
    }

    // Lock the mutex and update the counter
    pthread_mutex_lock(&lock);
    counter++;
    if (counter == 2) {
        pthread_cond_signal(&cond);
    }
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    // Initialize the mutex and condition variable
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    printf("Unsorted Array:\n");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int half_size = arr_size / 2;

    // Display the first half of the unsorted array
    printf("First Half of Array Unsorted:\n");
    for (int i = 0; i < arr_size / 2; i++) {
        first[i] = arr[i];
        printf("%d ", first[i]);
    }

    // Create the first thread to sort the first half
    pthread_t pid1, pid2, pid3;

    pthread_create(&pid1, NULL, SortArrays, first);
    // Display the other half of the unsorted array
    printf("\nOther Half of Array Unsorted:\n");
    int count = 0;
    for (int i = half_size; i < arr_size; i++) {
        half[count] = arr[i];
        printf("%d ", half[count]);
        count++;
    }
    // Create the second thread to sort the other half
    pthread_create(&pid2, NULL, SortArrays, half);

    pthread_mutex_lock(&lock);
    while (counter < 2) {
        pthread_cond_wait(&cond, &lock);
    }
    pthread_mutex_unlock(&lock);

    // Display the sorted first half
    printf("\nSorted Half Array:\n");
    for (int x = 0; x < half_size; x++) {
        printf("%d ", first[x]);
    }

    // Display the sorted other half
    printf("\nOther Sorted Half Array:\n");
    for (int x = 0; x < half_size; x++) {
        printf("%d ", half[x]);
    }

    // Merge the two sorted halves into the final array
    for (int x = 0; x < half_size; x++) {
        sort[x] = first[x];
    }

    int q = 0;
    for (int x = half_size; x < arr_size; x++) {
        sort[x] = half[q];
        q++;
    }

    // Create a thread to sort the merged array
    pthread_create(&pid3, NULL, fullSort, sort);
    pthread_join(pid3, NULL);

    // Display the sorted array
    printf("\nSorted New Array:\n");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", sort[i]);
    }

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0;
}


    pthread_exit(0);
}


