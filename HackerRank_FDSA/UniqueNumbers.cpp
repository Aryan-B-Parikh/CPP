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

    vector<int> unique;

    for (int i = 0; i < n; ) {
        int count = 1;
        while (i + count < n && arr[i] == arr[i + count])
            count++;

        if (count == 1)
            unique.push_back(arr[i]);

        i += count;
    }

    if (unique.empty())
        cout << -1;
    else {
        for (int x : unique)
            cout << x << " ";
    }

    return 0;
}
