
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    int arr[100];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cin >> target;

    int pos = binarySearch(arr, n, target);

    if(pos == -1) {
        cout << "Not Found";
        return 0;
    }

    while(pos < n && arr[pos] == target) {
        for(int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
