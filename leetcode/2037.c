#include <stdio.h>
#include <stdlib.h>

void print(int * arr) {
    for (int i=0; i<101; i++) {
        printf("%d ", arr[i]);
    }
}

int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
    int n = seatsSize;
    int count = 0;
    int seatsLocation[101] = {};
    int studsLocation[101] = {};
    for (int i=0; i<n; i++) {
        seatsLocation[seats[i]]++;
        studsLocation[students[i]]++;
    }
    int j = 0;
    for (int i=0; i<101; i++) {
        while (seatsLocation[i]) {
            while (!studsLocation[j]) {
                j++;
            }
            count += abs(i-j);
            printf("%d\t", count);
            seatsLocation[i]--;
            studsLocation[j]--;
        }
    }
    return count;
}

int main() {
    int seats[] = {4, 1, 5, 9};
    int students[] = {1, 3, 2, 6};
    int seatsSize = 4;
    int studentsSize = 4;
    int result = minMovesToSeat(seats, seatsSize, students, studentsSize);
    printf("%d\n", result);
    return 0;
}