#include <iostream>
#include <sstream>
using namespace std;

int main() 
{
    string line;
    getline(cin, line);

    string word;
    int maxLen = 0;

    stringstream ss(line);
    while (ss >> word) 
    {
        int len = word.length();
        if (len > maxLen) 
        {
            maxLen = len;
        }
    }

    cout << maxLen;
    return 0;
}
