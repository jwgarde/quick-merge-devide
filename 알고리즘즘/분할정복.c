#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}


void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int num;
    printf("�迭�� ũ�⸦ �Է��ϼ���: ");
    scanf("%d", &num);

    int* arr = (int*)malloc(num * sizeof(int));

    FILE* fp_in = fopen("data.txt", "r");
    if (fp_in == NULL) {
        printf("�Է� ������ �� �� �����ϴ�.\n");
        return 1;
    }

    for (int i = 0; i < num; i++) {
        if (fscanf(fp_in, "%d", &arr[i]) != 1) {
            printf("�Է� ������ ������ �߸��Ǿ����ϴ�.\n");
            return 1;
        }
    }

    fclose(fp_in);

    mergeSort(arr, 0, num - 1);

    FILE* fp_out = fopen("result.txt", "w");
    if (fp_out == NULL) {
        printf("��� ������ �� �� �����ϴ�.\n");
        return 1;
    }

    for (int i = 0; i < num; i++) {
        fprintf(fp_out, "%d ", arr[i]);
    }

    fclose(fp_out);
    free(arr);

    printf("���� ����� result.txt�� ����Ǿ����ϴ�.\n");

    return 0;
}
