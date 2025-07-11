#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int monthly_expenses[n];
    for(int i = 0; i < n; i++){
        cin >> monthly_expenses[i];
    }
    for(int i = 1; i < n; i++){
        int key = monthly_expenses[i];
        int j = i - 1;
        while(j >= 0 && monthly_expenses[j] > key){
            monthly_expenses[j + 1] = monthly_expenses[j];
            j--;
        }
        monthly_expenses[j + 1] = key;
    }
    for(int i = 0; i < n; i++){
        cout << monthly_expenses[i] << " ";
    }
    return 0;
}
