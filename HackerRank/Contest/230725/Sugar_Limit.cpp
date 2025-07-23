#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        int A[N], B[N];
        
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        
        int max_s = 0;
        
        for (int i = 0; i < N; i++) {
            int L = B[i];
            int S = 0;

            for (int j = 0; j < N; j++) {
                if (B[j] <= L && A[j] > 0) {
                    S += A[j];
                }
            }
            
            int s = S - L;
            max_s = max(max_s, s);
        }
        
        cout << max_s <<endl;
    }
    
    return 0;
}