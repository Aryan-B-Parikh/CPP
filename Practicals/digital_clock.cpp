#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

using namespace std;

void displayTime() {
    while (true) {
        // Get current time
        auto now = chrono::system_clock::now();
        time_t now_c = chrono::system_clock::to_time_t(now);
        tm *parts = localtime(&now_c);

        // Clear screen (Windows)
        system("cls");

        cout << "🕒 DIGITAL CLOCK\n\n";
        cout << "Time: "
             << setfill('0') << setw(2) << parts->tm_hour << ":"
             << setfill('0') << setw(2) << parts->tm_min << ":"
             << setfill('0') << setw(2) << parts->tm_sec << endl;

        // Wait 1 second
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    displayTime();
    return 0;
}
