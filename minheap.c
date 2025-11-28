
#include <stdio.h>

void heapify(int a[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && a[left] < a[smallest])
        smallest = left;
    if(right < n && a[right] < a[smallest])
        smallest = right;

    if(smallest != i) {
        int temp = a[i];
        a[i] = a[smallest];
        a[smallest] = temp;
        heapify(a, n, smallest);
    }
}

void buildMinHeap(int a[], int n) {
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i);
}

void heapSort(int a[], int n) {
    buildMinHeap(a, n);
    for(int i = n-1; i > 0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    heapSort(a, n);
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}

