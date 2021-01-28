#pragma once
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class HighScore
{
private:
	int score[6];
public:
	HighScore();
	void add_score(int n);
	int get_score(int ke);
	void load_score();
	void save_score();
	~HighScore();
};

