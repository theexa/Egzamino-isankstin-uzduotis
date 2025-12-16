#ifndef MYLIB_H
#define MYLIB_H

#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <regex>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using std::string;
using std::ifstream;
using std::ofstream;
using std::map;
using std::endl;
using std::cout;
using std::cin;

string cleanWord(string word);
void findUrls(const string& inputFile, const string& outputFile, const std::unordered_set<std::string>& tlds);
void countWords(const string& inputFile, const string& outputFile);
void createCrossReference(const string& inputFile, const string& outputFile);
std::unordered_set<std::string> loadTLDs(const std::string& filename);

#endif
