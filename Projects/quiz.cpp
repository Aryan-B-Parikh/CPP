#include <iostream>
#include <string>

using namespace std;

int main() {
    string questions[5] = {
        "1. What is the national animal of India?",
        "2. Who was the first Prime Minister of India?",
        "3. In which year did India gain independence?",
        "4. What is the capital city of India?",
        "5. Which river is considered the holiest in India?"
    };

    string options[5][4] = {
        {"1. Lion", "2. Tiger", "3. Elephant", "4. Peacock"},
        {"1. Mahatma Gandhi", "2. Jawaharlal Nehru", "3. Sardar Patel", "4. Dr. Rajendra Prasad"},
        {"1. 1945", "2. 1946", "3. 1947", "4. 1948"},
        {"1. Mumbai", "2. Kolkata", "3. New Delhi", "4. Chennai"},
        {"1. Yamuna", "2. Ganga", "3. Krishna", "4. Godavari"}
    };

    int answers[5] = {2, 2, 3, 3, 2}; // correct options (1-indexed)
    int score = 0;
    int userAnswer;

    cout << "🇮🇳 Welcome to the India Quiz! 🇮🇳\n\n";

    for (int i = 0; i < 5; i++) {
        cout << questions[i] << endl;
        for (int j = 0; j < 4; j++) {
            cout << options[i][j] << endl;
        }
        cout << "Enter your answer (1-4): ";
        cin >> userAnswer;

        if (userAnswer == answers[i]) {
            cout << "✅ Correct!\n\n";
            score++;
        } else {
            cout << "❌ Wrong! The correct answer was option " << answers[i] << ".\n\n";
        }
    }

    cout << "🎯 Quiz Over! Your Score: " << score << "/5\n";
    cout << (score >= 3 ? "👏 Great job!" : "💪 Keep learning!") << endl;

    return 0;
}
