#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 50

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[MAX_SIZE];
    int n = 0;


    FILE* input_file = fopen("data.txt", "r");
    if (input_file == NULL) {
        printf("오류: 입력 파일을 열 수 없습니다.\n");
        return 1;
    }

    while (fscanf(input_file, "%d", &arr[n]) == 1) {
        n++;
        if (n == MAX_SIZE) {
            printf("경고: 입력 파일에 %d개 이상의 정수가 있습니다. 초과된 정수는 무시됩니다.\n", MAX_SIZE);
            break;
        }
    }

   
    fclose(input_file);

    quickSort(arr, 0, n - 1);

    FILE* output_file = fopen("result.txt", "w");
    if (output_file == NULL) {
        printf("오류: 출력 파일을 열 수 없습니다.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(output_file, "%d ", arr[i]);
    }
    fclose(output_file);

    printf("정렬이 완료되었습니다.\n");

    return 0;
}
