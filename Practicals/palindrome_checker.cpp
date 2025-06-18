#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

// Function to check if a string is a palindrome
bool isPalindrome(string str) {
    // Remove non-alphanumeric characters and convert to lowercase
    string cleanStr;
    for (char c : str) {
        if (isalnum(c)) {
            cleanStr += tolower(c);
        }
    }

    // Check if the string is equal to its reverse
    string reversed = cleanStr;
    reverse(reversed.begin(), reversed.end());

    return cleanStr == reversed;
}

int main() {
    string input;
    cout << "🔁 Palindrome Checker 🔁\n";
    cout << "Enter a word or sentence: ";
    getline(cin, input);

    if (isPalindrome(input))
        cout << "✅ It's a palindrome!\n";
    else
        cout << "❌ Not a palindrome.\n";

    return 0;
}
