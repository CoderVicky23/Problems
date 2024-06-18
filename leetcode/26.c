#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int * nums, int numsSize) {
    if (numsSize == 1) return 1;
    int i = 0;
    int j = 0;
    while (j < numsSize) {
        if (nums[i] == nums[j]) {
            j++;
        }
        else {
            nums[i+1] = nums[j];
            i++;
            j++;
        }
    }
    return ++i;
}

int main() {
    FILE * ptr;
    ptr = fopen("input.txt", "r");

    int arr[101];
    int k = 0;
    int a;

    while (fscanf(ptr, "%d", &a) > 0) {
        arr[k] = a;
        k++;
    }

    fclose(ptr);

    a = removeDuplicates(arr, k);
    printf("%d\n",  a);
    for (int i=0; i<a; i++) {
        printf("%d\t", arr[i]);
    }

    return 0;
}