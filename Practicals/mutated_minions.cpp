#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;  // Number of test cases

    while (T--) {
        int N, K;
        cin >> N >> K;  // Read number of minions and the added value

        int count = 0;  // Counter for Wolverine-like minions

        for (int i = 0; i < N; ++i) {
            int value;
            cin >> value;

            if ((value + K) % 7 == 0) {
                count++;
            }
        }

        cout << count << endl;  // Print the result for the current test case
    }

    return 0;
}
