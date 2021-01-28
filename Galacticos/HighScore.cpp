#include "HighScore.h"

HighScore::HighScore()
{
	for (int i = 0; i < 5; i++)
	{
		score[i] = 0;
	}
}

void HighScore::add_score(int n)
{
	score[5] = n;
	int temp;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (score[i] > score[j]) {
				temp = score[i];
				score[i] = score[j];
				score[j] = temp;
			}
		}
	}
}

int HighScore::get_score(int ke) {
	return score[ke];
}

void HighScore::load_score() 
{
	ifstream f;
	string scrstr;
	f.open("Picture\\save.txt");
	if(f.is_open())
	{
		int ctr = 0;
		while (f.eof()==false)
		{
			getline(f, scrstr);
			stringstream(scrstr) >> score[ctr];
			ctr++;
		}
	}
	f.close();
}

void HighScore::save_score() 
{
	ofstream f;
	string scrstr;
	f.open("Picture\\save.txt");
	if (f.is_open())
	{
		int ctr = 0;
		for (int i = 0; i < 5; i++)
		{
			stringstream ss;
			if (i < 4)
			{
				ss << score[i] << "\n";
			}
			else {
				ss << score[i];
			}
			f <<ss.str();
		}
	}
    f.close();
}

HighScore::~HighScore()
{
}
