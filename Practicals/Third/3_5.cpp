#include <iostream>
using namespace std;

int digitSum(long long n) {
    if (n < 10) {
        return n;
    }
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return digitSum(sum);
}

int superDigit(string n, int k) {
    long long initialSum = 0;
    for (char digit : n) {
        initialSum += digit - '0';
    }
    long long totalSum = initialSum * k;
    return digitSum(totalSum);
}

int main() {
    string n;
    int k;
    cin >> n >> k;
    cout << superDigit(n, k) << endl;
    return 0;
}
