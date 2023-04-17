#include "pch.h"

using namespace std;

// Writer: Isaac
TEST(MorseTest, TranslationTest1) {

    string morseInput = "-.-- . ...";
    string expected = "yes";

    EXPECT_EQ(translator(morseInput), expected);
}

// Writer: Isaac
TEST(MorseTest, TranslationTest2) {

    string morseInput = "-. ---";
    string expected = "no";

    EXPECT_EQ(translator(morseInput), expected);
}

// Writer: Isaac
TEST(MorseTest, NoTranslationTest1) {

    string morseInput = "--------"; // Something that we dont plan on recognizing
    string reactionExample[] = { "| o_o |" , "( o.o )", "|o o  |", "bro... c'mon." }; // Placeholder things to compare to
    string expected = "no";

    // No clue how to write this one well, if it works then it should throw a fail for every reaction that isnt matched but one will
    // If nothing matches then the test overall fails
    // IF multiple things match... uh oh.
    string result = translator(morseInput);
    bool matchFound = false;
    for (int j = 0; j < 4; ++j) {
        cout << result << endl;
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

// Writer: Kristen
TEST(FileSearchTest, TestNotFoundWordInFile) {
    char filename[] = "wordList.txt";
    string nonDesiredWord = "world";
    bool notFound = findWordInFile(filename, nonDesiredWord);
    ASSERT_FALSE(notFound);
}

// Writer: Kristen
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

// Writer: Kristen
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

// Writer: Kristen
// Test case that checks if a user input is a valid math problem
TEST_F(MathProblemTest, MathProblemFail) {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(1, 100);
    int num1 = dist(rng);
    int num2 = dist(rng);

    int input = (num1 + num2) + 1;

    EXPECT_FALSE(solveMathProblem(num1, num2, input));
}
