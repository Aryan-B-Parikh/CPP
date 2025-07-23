#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int N, C;
        cin >> N >> C;
        
        int A[N];
        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }
        
        int original_C = C;
        
        int min_friend = A[0];
        for(int i = 1; i < N; i++) {
            if(A[i] < min_friend) {
                min_friend = A[i];
            }
        }
        
        if(C <= min_friend) {
            C = min_friend + 1;
        }
        
        sort(A, A + N);
        
        for(int i = 0; i < N; i++) {
            if(C == A[i]) {
                C++;
            }
        }
        
        cout << C - original_C << endl;
    }
    
    return 0;
}