#ifndef EXTENSION_H_
#define EXTENSION_H_

#include "CommonFunction.h"
#include<fstream>
#include<sstream>
#include<string>
std::string GetHighScoreFromFile(std::string path);

void updateHighScore(std::string path,
	const int& score,
	const std::string& old_high_score);
void resetHighScore(std::string path);

#endif

