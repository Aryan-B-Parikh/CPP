#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main() {
    vector<string> quotes = {
        "🚀 Push yourself, because no one else is going to do it for you.",
        "🔥 Success doesn’t come to you, you go to it.",
        "🌱 Great things never come from comfort zones.",
        "💡 Dream it. Wish it. Do it.",
        "🎯 Stay focused, go after your dreams and keep moving toward your goals.",
        "🧠 Don’t watch the clock; do what it does. Keep going."
    };

    srand(time(0)); // seed the random generator
    int index = rand() % quotes.size();

    cout << "\n✨ Quote of the Day ✨\n";
    cout << quotes[index] << endl;

    return 0;
}
