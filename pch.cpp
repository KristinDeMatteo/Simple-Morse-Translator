//
// pch.cpp
// Include the standard header and generate the precompiled header.
//

#include "pch.h"

using namespace std;

// Translates any predefined morse code input into a language
// Written by Kristin

// If input is not morse code, print out random ascii from txt file
void printAsciiFile() {
    ifstream asciiFile("ascii.txt");
    if (!asciiFile) {
        cerr << "Error opening file ascii.txt" << endl;
        return;
    }

    vector<string> sections;
    string line;
    while (getline(asciiFile, line)) {
        if (line.find(';') != string::npos) {
            sections.push_back("");
        }
        else {
            sections.back() += line + "\n";
        }
    }

    if (sections.size() < 2) {
        cerr << "ascii.txt does not contain at least 2 sections" << endl;
        return;
    }

    srand(time(nullptr));
    int sectionIndex = rand() % (sections.size() - 1);

    cout << sections[sectionIndex];
    asciiFile.close();
}

// Returns a random ascii image if a morse input is not recognized
string badInput() {
    string reaction[] = { "| o_o |" , "( o.o )", "|o o  |", "bro... c'mon." };
    srand(time(nullptr));
    int x = rand() % 4;
    return reaction[x];
}

string translator(string input) {
    // Morse code map
    map<string, string> morseMap = {
        {".-", "a"},
        {"-...", "b"},
        {"-.-.", "c"},
        {"-..", "d"},
        {".", "e"},
        {"..-.", "f"},
        {"--.", "g"},
        {"....", "h"},
        {"..", "i"},
        {".---", "j"},
        {"-.-", "k"},
        {".-..", "l"},
        {"--", "m"},
        {"-.", "n"},
        {"---", "o"},
        {".--.", "p"},
        {"--.-", "q"},
        {".-.", "r"},
        {"...", "s"},
        {"-", "t"},
        {"..-", "u"},
        {"...-", "v"},
        {".--", "w"},
        {"-..-", "x"},
        {"-.--", "y"},
        {"--..", "z"}
    };

    string morseInput;
    stringstream ss(input);
    string code, result = "";
    while (ss >> code) {
        if (morseMap.find(code) != morseMap.end()) {
            result += morseMap[code];
        }
        else {
            // If code is incorrect, program shames you.
            result = badInput();
            break;
        }
    }
    return result;
}

string returner(string word) {
    string filename = word + ".txt";
    ifstream wordFile(filename);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(1, 6);
    int line = dist(rng); //Random number for picking random language translation of word

    if (!wordFile.is_open()) {
        cout << "Unable to open file." << endl;
        return "something went really bad :(";
    }

    string language;
    for (int i = 1; i <= line; ++i) {
        if (!getline(wordFile, language)) {
            std::cerr << "File contains fewer than " << line << " lines." << std::endl;
            return "";
        }
    }
    return language;
}

bool findWordInFile(char filename[], string word) {
    string list;
    ifstream wordList(filename);

    if (!wordList.is_open()) {
        cout << "Unable to open file wordList." << endl;
        return false;
    }

    string line;
    while (getline(wordList, line)) {
        if (line.find(word) == false) {
            return true;
        }
    }

    return false;

}

// Function that generates a random math problem
bool solveMathProblem(int num1, int num2, int input) {
    int solution = num1 + num2;

    if (input == solution) {
        return true;
    }
    else {
        return false;
    }
}