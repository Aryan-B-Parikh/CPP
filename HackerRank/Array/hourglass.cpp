#include<iostream>

using namespace std;

int main()
{
    int arr[6][6];
    int max_sum = -32768;
    int current_sum;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i<4;i++)
    {
        for(int j =0 ;j<4;j++)
        {
            current_sum=arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
            if(current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }
    cout << max_sum << endl;
    return 0;
}