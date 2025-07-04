#include <iostream>
using namespace std;


int linearSearch(int arr[], int n, int x, int &comparisons) {
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int x;
    cin >> x;

    int comparisons = 0;
    int index = linearSearch(arr, n, x, comparisons);

    if (index != -1) {
        cout << index << endl;
        cout << comparisons << endl;
    } else {
        cout << "Element " << x << " is not present in the array" << endl;
        cout << comparisons << endl;
    }

    return 0;
}
