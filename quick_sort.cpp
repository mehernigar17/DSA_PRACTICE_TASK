
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& a, int low, int high) {
    int pivot = a[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (a[i] <= pivot && i <= high - 1) {
            i++;
        }
        while (a[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(a[i], a[j]);
        }
    }

    swap(a[low], a[j]);
    return j;
}

void quick_sort(vector<int>& a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quick_sort(a, low, pi - 1);
        quick_sort(a, pi + 1, high);
    }
}

int main() {
    vector<int> a = {1, 2, 6, 9, 4, 5, 8};

    quick_sort(a, 0, a.size() - 1);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }

    return 0;
}
