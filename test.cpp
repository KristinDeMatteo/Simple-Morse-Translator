#include "pch.h"
#include <iostream>
#include <sstream>
#include <map>
#include <cstdlib> // for rand() function
#include <ctime>   // for time() function

using namespace std;

// Translates any predefined morse code input into a language
// Written by Kristin

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
    
    stringstream ss(morseInput);
    string code, result = "";
    while (ss >> code) {
        if (morseMap.find(code) != morseMap.end()) {
            result += morseMap[code];
        } else {
			// If code is incorrect, program shames you.
			string reaction[] = { "| o_o |" , "( o.o )", "|o o  |", "bro... c'mon."};
			srand(time(nullptr));
			int x = rand() % 4;
            result = reaction[x];
            break;
        }
    }
    return result;
}

// Returns a random ascii image if a morse input is not recognized
string badInput() {
	return "";
}

bool findWordInFile(char filename[], string word) {
    // function code here
	return 0;
}

// Function that generates a random math problem
string generateMathProblem() {
  	return "";
}

// Function that checks if a given string is a valid math problem
bool isMathProblem(const string& str) {
  	return 0;
}

TEST(MorseTest, TranslationTest1) {

	string morseInput = "- .-- . ...";
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
	string reactionExample[] = { "| o_o |" , "( o.o )", "|o o  |", "bro... c'mon."}; // Placeholder things to compare to
	string expected = "no";

	// No clue how to write this one well, if it works then it should throw a fail for every reaction that isnt matched but one will
	// If nothing matches then the test overall fails
	// IF multiple things match... uh oh.
	for (int i = 0; i < 4; ++i) {
		EXPECT_EQ(translator(morseInput), reactionExample[i]);
	}

}

// Tests for Finding a word in file written by Kristin
TEST(FileSearchTest, TestFoundWordInFile) {
    char filename[] = "example.txt";
    string desiredWord = "hello";
    bool found = findWordInFile(filename, desiredWord);
    ASSERT_TRUE(found);
}

TEST(FileSearchTest, TestNotFoundWordInFile) {
    char filename[] = "example.txt";
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
TEST_F(MathProblemTest, GeneratesValidMathProblem) {
	string problem = generateMathProblem();
  	EXPECT_TRUE(isMathProblem(problem));
}

// Test case that checks if a user input is a valid math problem
TEST_F(MathProblemTest, UserInputIsMathProblem) {
	// Simulate user input
	string userInput = "2+3?";
	EXPECT_TRUE(isMathProblem(userInput));
}

// Test case that checks if a user input is not a valid math problem
TEST_F(MathProblemTest, UserInputIsNotMathProblem) {
	// Simulate user input
	string userInput = "hello world";
	EXPECT_FALSE(isMathProblem(userInput));
}
