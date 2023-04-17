#include "pch.h"

using namespace std;

int main() {
    int count = 0;
    int num1, num2, input;

    while (true) {
        cout << "Please enter morse code (type 'exit' to exit): ";
        string input;
        getline(cin, input);

        if (input == "exit") {
            break;
        }

        string output = translator(input);
        
        bool match = false;

        // If incorrect input given, also generates random ascii cat
        bool matchFound = false;
        string reactionExample[] = { "| o_o |" , "( o.o )", "|o o  |", "bro... c'mon." };
        for (int j = 0; j < 4; ++j) {
            if (output == reactionExample[j]) {
                match = true;
                printAsciiFile();
                break;
            }
        }
        if (match == true) {
            cout << "Output: " << output << endl;
        } else{
            output = returner(output);
            cout << "Output: " << output << endl;
        }

        count++;
        if (count >= 3 && rand() % 2 == 0) {
            mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
            uniform_int_distribution<int> dist(1, 10);
            int num1 = dist(rng);
            int num2 = dist(rng);

            cout << "Solve the following problem: " << num1 << " + " << num2 << " = ";
            cin >> input;

            if (solveMathProblem(num1, num2, stoi(input))) {
                cout << "Correct!" << endl;
            }
            else {
                cout << "Incorrect." << endl;
            }

            // clear input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (count >= 5) {
            count = 0;
        }
    }

    return 0;
}
