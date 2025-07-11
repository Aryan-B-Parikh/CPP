#include<iostream>

using namespace std;

void booble_sort(int roll_no[], int n, int time[]){
    int swaps=0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(time[j] > time[j + 1]){
                swaps++;
                swap(time[j], time[j + 1]);
                swap(roll_no[j], roll_no[j + 1]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << roll_no[i];
        cout << " " << time[i] << endl;
    }
    cout<<swaps << endl;
}
void selection_sort(int roll_no[], int n, int time[]){
    int swaps = 0;
    for(int i = 0; i < n - 1; i++){
        int min_index = i;
        for(int j = i + 1; j < n; j++){
            if(time[j] < time[min_index]){
                min_index = j;
            }
        }
        if(min_index != i) {
            swaps++;
        }
        swap(time[i], time[min_index]);
        swap(roll_no[i], roll_no[min_index]);
    }
    for(int i = 0; i < n; i++){
        cout << roll_no[i] << " ";
        cout << time[i] << endl;
    }
    cout << swaps << endl;
}
int main(){
    int n;
    cin >> n;
    int roll_no[n];
    int time[n];
    for(int i = 0; i < n; i++){
        cin >> roll_no[i];
        cin >> time[i];
    }
    int select;
    cin >> select;
    switch (select)
    {
    case 1:
        booble_sort(roll_no, n, time);
        break;
    case 2:
        selection_sort(roll_no, n, time);
        break;
    }
    cout<<roll_no[0] << "," <<roll_no[1]<< endl;
    return 0;
}