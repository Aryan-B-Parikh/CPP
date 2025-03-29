#include <iostream>
using namespace std;

template <typename T>
void display(T* arr, int size) {
    cout << "Collection: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
T findMax(T* arr, int size) {
    T maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

template <typename T>
void reverseArray(T* arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        T temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int main() {
    int n;

    cout << "Enter size of integer collection: ";
    cin >> n;
    int* intArr = new int[n];
    cout << "Enter integer elements: ";
    for (int i = 0; i < n; i++) {
        cin >> intArr[i];
    }

    display(intArr, n);
    cout << "Maximum value: " << findMax(intArr, n) << endl;
    reverseArray(intArr, n);
    display(intArr, n);
    delete[] intArr;

    cout << "\nEnter size of float collection: ";
    cin >> n;
    float* floatArr = new float[n];
    cout << "Enter float elements: ";
    for (int i = 0; i < n; i++) {
        cin >> floatArr[i];
    }

    display(floatArr, n);
    cout << "Maximum value: " << findMax(floatArr, n) << endl;
    reverseArray(floatArr, n);
    display(floatArr, n);
    delete[] floatArr;

    cout << "\nEnter size of character collection: ";
    cin >> n;
    char* charArr = new char[n];
    cout << "Enter character elements: ";
    for (int i = 0; i < n; i++) {
        cin >> charArr[i];
    }

    display(charArr, n);
    cout << "Maximum value: " << findMax(charArr, n) << endl;
    reverseArray(charArr, n);
    display(charArr, n);
    delete[] charArr;

    return 0;
}
