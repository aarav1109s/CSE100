#include <iostream>
#include <vector>


using namespace std;

void mergeSort(int* arr, int l, int h);
void merge(int* arr, int l, int m, int h);

int main() {

    int x;
    cin >> x;

    int* arr = new int[x];

    int numbers;


    for (int i = 0; i < x; i++) {
        cin >> arr[i];
    }

    int length = sizeof(arr) / sizeof(arr[0]);


    mergeSort(arr, 0, x - 1);

    for (int i = 0; i < x; i++) {
        cout << arr[i] << ";";
    }

    cout << endl;

    delete[] arr;



    return 0;
}

void merge(int* arr, int l, int m, int h) {
    int n1 = m - l + 1;
    int n2 = h - m;

    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[i + l];
    }

    for (int i = 0; i < n2; i++) {
        R[i] = arr[i + 1 + m];
    }

    int i = 0;
    int j = 0;
    int k = l;

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


}


void mergeSort(int* arr, int l, int h) {
    if (l >= h) return;

    int m = (l + h) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, h);

    merge(arr, l, m, h);
}


