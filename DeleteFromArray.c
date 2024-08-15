#include <stdio.h>
#include <stdlib.h>

int deleteElement(int arr[], int n, int item) {
    int idx = -1;
    for(int i = 0; i < n; i++) {
        if (arr[i] == item) {
            idx = i;
        }
    }
    if (idx == -1) {
        printf("Could not find specified item, exiting...");
        abort();
    }
    for (int i = idx; i < n; i++) {
        arr[i] = arr[i+1];
    }
    return n - 1;
}

int main(int argc, char **argv) {
    int myArr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(myArr) / sizeof(myArr[0]);
    int myItem = 3;
    printf("Original Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", myArr[i]);
    }
    printf("\nArray After Deletion:\n");
    n = deleteElement(myArr, n, myItem);
    for (int i = 0; i < n; i++) {
        printf("%d ", myArr[i]);
    }
}
