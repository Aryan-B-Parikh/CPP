#include <bits/stdc++.h>
using namespace std;

int main() {

    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        long long A[N + K];
        long long total_sum = 0;
        
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            total_sum += A[i];
        }
        
        int current_size = N;
        
        for (int i = 0; i < K; i++) {

            sort(A, A + current_size);
            
            long long min1 = A[0];
            long long min2 = A[1];
            
            long long new_val = (min1 + min2 + 1) / 2;
            
            A[current_size] = new_val;
            current_size++;
            total_sum += new_val;
        }
        
        cout << total_sum << endl;
    }
    
    return 0;
}
