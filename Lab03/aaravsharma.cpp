#include <iostream>
#include <climits>
using namespace std;

int crossingSubarray(int arr[], int low, int mid, int high) {

    int currentSum = 0;
    int maxLeft = INT_MIN;
    int maxRight = INT_MIN;

    for (int i = mid; i >= low; i--) {
        currentSum += arr[i];
        if (currentSum > maxLeft) {
            maxLeft = currentSum;
        }
    }

    currentSum = 0;

    for (int j = mid + 1; j <= high; j++) {
        currentSum += arr[j];
        if (currentSum > maxRight) {
            maxRight = currentSum;
        }
    }

    return maxLeft + maxRight;

}

int solve(int arr[], int low, int high) {

    if (low == high) return arr[low];

    int mid = (low + high) / 2;

    int left = solve(arr, low, mid);
    int right = solve(arr, mid + 1, high);
    int cross = crossingSubarray(arr, low, mid, high);

    return max(left, max(right, cross));

}


int main() {

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << solve(arr, 0, n-1);

    return 0;
}