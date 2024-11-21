#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100

// 랜덤 숫자 생성(배열의 각 요소 0-999 사이의 난수를 채움)
void generateRandomNumbers(int array[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 1000;
    }
}

// Shell Sort 구현
// divisor: 간격을 계산하는 방식
// comparisons : 비교 한 횟수를 저장한 포인터
// moves : 이동횟수를 가리키는 포인터
void doShellSort(int array[], int divisor, int* comparisons, int* moves) {
    int tempArray[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        tempArray[i] = array[i];
    }
    int localComparisons = 0, localMoves = 0;

    printf("Shell Sort (n/%d):\n", divisor);
    int gap = ARRAY_SIZE / divisor;
    // gap이 0이 될 때 까지 반복한다
    while (gap > 0) {
        printf("Sorting with gap = %d: ", gap);
        for (int i = 0; i < 20 && i < ARRAY_SIZE; i++) { // 앞 20개 출력
            printf("%d ", tempArray[i]);
        }
        if (ARRAY_SIZE > 20) {
            printf("..."); // 배열 20개이상 생략표시
        }
        printf("\n");

        for (int i = gap; i < ARRAY_SIZE; i++) {
            int temp = tempArray[i];// 현재 요소를 temp에 저장
            localMoves++; // temp 값 할당
            int j = i;
            //gap간격 만큼 떨어진 요소를 비교하면서 정렬
            while (j >= gap && tempArray[j - gap] > temp) {
                tempArray[j] = tempArray[j - gap];
                localComparisons++;
                localMoves++;
                j -= gap;
            }
            tempArray[j] = temp;
            localMoves++;
        }
        gap /= divisor;// gap 크기를 줄인다
    }

    *comparisons = localComparisons;//총 비교 횟수
    *moves = localMoves;//총 이동횟수

    printf("Sorted shellArray (gap = %d): ", divisor);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", tempArray[i]);
    }
    printf("\n");
}

// Insertion Sort 구현핞 함수
void doInsertionSort(int array[], int* comparisons, int* moves) {
    int tempArray[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        tempArray[i] = array[i];
    }
    int localComparisons = 0, localMoves = 0;

    printf("Insertion Sort:\n");
    for (int i = 1; i < ARRAY_SIZE; i++) {
        int temp = tempArray[i];
        localMoves++;
        int j = i - 1;

        while (j >= 0 && tempArray[j] > temp) {
            tempArray[j + 1] = tempArray[j];
            localComparisons++;
            localMoves++;
            j--;
        }
        tempArray[j + 1] = temp;
        localMoves++;
    }

    printf("Sorted insertionArray: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", tempArray[i]);
    }
    printf("\n");

    *comparisons = localComparisons;
    *moves = localMoves;
}

int main() {
    int array[ARRAY_SIZE];
    int comparisonCount, moveCount;

    
    generateRandomNumbers(array);

    // Shell Sort (n/2)
    printf("Shell Sort (n/2):\n");
    doShellSort(array, 2, &comparisonCount, &moveCount);
    printf("Shell Sort (n/2) - Comparisons: %d, Moves: %d\n\n", comparisonCount, moveCount);

    // Shell Sort (n/3)
    printf("Shell Sort (n/3):\n");
    doShellSort(array, 3, &comparisonCount, &moveCount);
    printf("Shell Sort (n/3) - Comparisons: %d, Moves: %d\n\n", comparisonCount, moveCount);

    // Insertion Sort
    printf("Insertion Sort:\n");
    doInsertionSort(array, &comparisonCount, &moveCount);
    printf("Insertion Sort - Comparisons: %d, Moves: %d\n", comparisonCount, moveCount);

    return 0;
}
