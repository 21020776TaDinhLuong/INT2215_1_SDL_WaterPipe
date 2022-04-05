#include "Extension.h"
std::string GetHighScoreFromFile(std::string path)
{
	std::fstream HighScoreFile;
	std::string highscore;

	HighScoreFile.open(path, std::ios::in);
	HighScoreFile >> highscore;

	return highscore;
}
void updateHighScore(std::string path,
	const int& score,
	const std::string& old_high_score)
{
	int oldHighScore = 0;
	std::fstream HighScoreFile;
	std::string newHighScore;
	std::stringstream ConvertStringToInt(old_high_score);

	HighScoreFile.open(path, std::ios::out);

	ConvertStringToInt >> oldHighScore;
	if (score > oldHighScore)
	{
		oldHighScore = score;
	}
	newHighScore = std::to_string(oldHighScore);

	HighScoreFile << newHighScore;
}
void resetHighScore(std::string path)
{
	int oldHighScore = 0;
	std::fstream HighScoreFile;
	

	HighScoreFile.open(path, std::ios::out);
	HighScoreFile << 0;
}