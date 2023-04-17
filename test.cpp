#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <random>
#include <chrono>
#include <cstdlib> // for rand() function
#include <ctime>   // for time() function

using namespace std;

// Translates any predefined morse code input into a language
// Written by Kristin

// Returns a random ascii image if a morse input is not recognized
string badInput() {
    string reaction[] = { "| o_o |" , "( o.o )", "|o o  |", "bro... c'mon." };
    srand(time(nullptr));
    int x = rand() % 4;
    return reaction[x];;
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
    uniform_int_distribution<int> dist(0, 5);
    int line = dist(rng); //Random number for picking random language translation of word

    if (!wordFile.is_open()) {
        cout << "Unable to open file wordList." << endl;
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

// Function that checks if a given string is a valid math problem
//bool isMathProblem(const string& str) {
//    return 0;
//}

TEST(MorseTest, TranslationTest1) {

    string morseInput = "-.-- . ...";
    string expected = "yes";

    EXPECT_EQ(translator(morseInput), expected);
}

TEST(MorseTest, TranslationTest2) {

    string morseInput = "-. ---";
    string expected = "no";

    EXPECT_EQ(translator(morseInput), expected);
}

TEST(MorseTest, NoTranslationTest1) {

    string morseInput = "--------"; // Something that we dont plan on recognizing
    string reactionExample[] = { "| o_o |" , "( o.o )", "|o o  |", "bro... c'mon." }; // Placeholder things to compare to
    string expected = "no";

    // No clue how to write this one well, if it works then it should throw a fail for every reaction that isnt matched but one will
    // If nothing matches then the test overall fails
    // IF multiple things match... uh oh.
    string result = translator(morseInput);
    bool matchFound = false;
    for (int j = 0; j < 3; ++j) {
        if (result == reactionExample[j]) {
            matchFound = true;
            break;
        }
    }
    EXPECT_TRUE(matchFound);
}

// Tests for Finding a word in file written by Kristin
TEST(FileSearchTest, TestFoundWordInFile) {
    char filename[] = "wordList.txt";
    string desiredWord = "hello";
    bool found = findWordInFile(filename, desiredWord);
    ASSERT_TRUE(found);
}

TEST(FileSearchTest, TestNotFoundWordInFile) {
    char filename[] = "wordList.txt";
    string nonDesiredWord = "world";
    bool notFound = findWordInFile(filename, nonDesiredWord);
    ASSERT_FALSE(notFound);
}

TEST(FileSearchTest, TestNonExistingFile) {
    char nonExistingFile[] = "nonexisting.txt";
    string desiredWord = "hello";
    bool fileNotFound = findWordInFile(nonExistingFile, desiredWord);
    ASSERT_FALSE(fileNotFound);
}

// Tests for random math problem occurrence written by Kristin

// Test fixture for the math problem feature
class MathProblemTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Seed the random number generator
        srand(time(nullptr));
    }
};

// Test case that checks if a generated math problem is valid
TEST_F(MathProblemTest, MathProblemPass) {
    //string problem = generateMathProblem();
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(1, 100);
    int num1 = dist(rng);
    int num2 = dist(rng);

    int input = num1 + num2;

    EXPECT_TRUE(solveMathProblem(num1, num2, input));
}

// Test case that checks if a user input is a valid math problem
TEST_F(MathProblemTest, MathProblemFail) {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(1, 100);
    int num1 = dist(rng);
    int num2 = dist(rng);

    int input = (num1 + num2) + 1;

    EXPECT_FALSE(solveMathProblem(num1, num2, input));
}