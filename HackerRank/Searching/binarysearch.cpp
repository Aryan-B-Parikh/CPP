#include <iostream>
using namespace std;


int binarySearch(int roll[], int time[], int n, int key, int &comparisons) {
    int low = 0, high = n - 1;

    while (low <= high) {
        comparisons++;
        int mid = (low + high) / 2;

        if (roll[mid] == key)
            return time[mid];
        else if (roll[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    int roll[n], time[n];

    for (int i = 0; i < n; i++) {
        cin >> roll[i] >> time[i];
    }

    int key;
    cin >> key;

    int comparisons = 0;
    int result = binarySearch(roll, time, n, key, comparisons);

    if (result != -1) {
        cout << result << endl;
        cout << comparisons << endl;
    } else {
        cout << "Not submitted" << endl;
    }

    return 0;
}
