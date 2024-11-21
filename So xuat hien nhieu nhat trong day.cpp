#include <stdio.h>

#define MAX_LEN 100
#define MAX_VALUE 30000

void findMostFrequent(int arr[], int n) {
    int freq[MAX_VALUE + 1] = {0};  
    int maxFreq = 0; 
    int i, j;

    for (i = 0; i < n; i++) {
        freq[arr[i]]++;
        if (freq[arr[i]] > maxFreq) {
            maxFreq = freq[arr[i]];  
        }
    }


    printf("Cac so xuat hien nhieu lan nhat (%d l?n) la:\n", maxFreq);
    for (i = 0; i < n; i++) {
        
        if (freq[arr[i]] == maxFreq) {
            printf("%d ", arr[i]);
            freq[arr[i]] = 0;  
        }
    }
}

int main() {
    int arr[MAX_LEN];
    int n, i;

    printf("Nhap so luong phan tu trong day (khong qua 100): ");
    scanf("%d", &n);

    printf("Nhap cac phan tu trong day:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findMostFrequent(arr, n);  

    return 0;
}

