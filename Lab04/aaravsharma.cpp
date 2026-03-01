#include <iostream>
using namespace std;


void maxHeapify(int arr[], int i, int heap_size) {
    int l = 2 * i + 1;  
    int r = 2 * i + 2;  
    int largest = i;

    if (l < heap_size && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < heap_size && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest, heap_size);
    }
}


void buildMaxHeap(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        maxHeapify(arr, i, n);
    }
}


void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);   
        maxHeapify(arr, 0, i);  
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    heapSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ";";
    }

    return 0;
}