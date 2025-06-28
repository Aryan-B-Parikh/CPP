#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    vector<int> duplicates;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            if (duplicates.empty() || duplicates.back() != arr[i])
                duplicates.push_back(arr[i]);
        }
    }

    if (duplicates.empty())
        cout << -1;
    else {
        for (int x : duplicates)
            cout << x << " ";
    }

    return 0;
}
