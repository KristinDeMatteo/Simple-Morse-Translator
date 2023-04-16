#include "pch.h"

using namespace std;

// Translates any predefined morse code input into a language
string translator(string input) {
	return "";
}

// Returns a random ascii image if a morse input is not recognized
string badInput() {
	return "";
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
	string reactionExample[] = { "| o_o |" , "( o.o )", "|o o  |"}; // Placeholder things to compare to
	string expected = "no";

	// No clue how to write this one well, if it works then it should throw a fail for every reaction that isnt matched but one will
	// If nothing matches then the test overall fails
	// IF multiple things match... uh oh.
	for (int i = 0; i < 3; ++i) {
		EXPECT_EQ(translator(morseInput), reactionExample[i]);
	}

}