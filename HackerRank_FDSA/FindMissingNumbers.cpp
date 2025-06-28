#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr;
    int temp;

    while (cin >> temp)
        arr.push_back(temp);

    vector<bool> seen(n + 1, false);

    for (int num : arr) {
        if (num >= 1 && num <= n)
            seen[num] = true;
    }

    vector<int> missing;
    for (int i = 1; i <= n; i++) {
        if (!seen[i])
            missing.push_back(i);
    }

    if (missing.empty())
        cout << -1;
    else {
        for (int num : missing)
            cout << num << " ";
    }

    return 0;
}
