#pragma once
#include "wx\wx.h"
#include "MainFrame.h"
#include "Bullet.h"
#include "NormalBullet.h"
#include "Laser.h"
#include "Missile.h"
#include "Monster.h"
#include "SmallMonster.h"
#include "MediumMonster.h"
#include "LargeMonster.h"
#include "Spaceship.h"
#include "HighScore.h"
#include <vector>

using namespace std;

class MainWindow : public wxWindow
{
public:
	MainWindow(MainFrame *parent);
	~MainWindow();
	void LoadPlayer();
	void LoadMonster(wxTimerEvent &event);
	void addmonster();
	void GenerateBullet();
	void GenerateMissile();
	void OnPaint(wxPaintEvent &event);
	void OnKeyDown(wxKeyEvent &event);
	void OnTimer(wxTimerEvent &event);
private:
	int level, ctrmissile, score, ctrspawnmonster,ctrmovebullet, ctrkillmonster;
	bool allowshoot, allowspawn;
	MainFrame * parent=nullptr;
	wxTimer *timer, *monsterTimer;
	wxBitmap *backBitmap = nullptr;
	Spaceship *player = nullptr;
	HighScore hs;
	vector<Monster*> monster;
	vector<Bullet*> bullet;
	void LoadBackImageBitmap();
	DECLARE_EVENT_TABLE()
};