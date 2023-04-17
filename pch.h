//
// pch.h
// Header for standard system include files.
//

#pragma once

#include "gtest/gtest.h"
#include <string>

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <random>
#include <chrono>
#include <cstdlib> // for rand() function
#include <ctime>   // for time() function

std::string badInput();
std::string translator(std::string input);
std::string returner(std::string word);
bool findWordInFile(char filename[], std::string word);
bool solveMathProblem(int num1, int num2, int input);
void printAsciiFile();