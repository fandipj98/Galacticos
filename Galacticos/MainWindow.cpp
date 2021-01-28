#include "MainWindow.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/dcbuffer.h>

#define TIMER_ID 2000
#define TIMER_ID1 2001

BEGIN_EVENT_TABLE(MainWindow, wxWindow)
	EVT_PAINT(MainWindow::OnPaint)
	EVT_KEY_DOWN(MainWindow::OnKeyDown)
	EVT_TIMER(TIMER_ID, MainWindow::OnTimer)
	EVT_TIMER(TIMER_ID1, MainWindow::LoadMonster)
END_EVENT_TABLE()

MainWindow::MainWindow(MainFrame *parent)	: wxWindow(parent, wxID_ANY)
{
	level = 1;
	score = 0;
	ctrmissile = 0;
	ctrmovebullet = 20;
	ctrspawnmonster = 0;
	ctrkillmonster = 0;
	allowshoot = true;
	allowspawn = true;
	hs = HighScore();
	hs.load_score();
	this->parent = parent;
	this->SetBackgroundColour(wxColour(*wxWHITE));
	timer = new wxTimer(this, TIMER_ID);
	monsterTimer = new wxTimer(this, TIMER_ID1);

	timer->Start(25);
	monsterTimer->Start(75);

	SetFocus();

	wxImageHandler *jpegLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpegLoader);
	//load image
	this->LoadBackImageBitmap();
	this->LoadPlayer();

}

MainWindow::~MainWindow()
{
	bullet.clear();
	monster.clear();
	timer->Stop();
	monsterTimer->Stop();
	delete timer;
	delete monsterTimer;
	delete backBitmap;
	delete player;
}

void MainWindow::LoadBackImageBitmap()
{
	wxImage image(wxT("Picture\\background.jpg"),wxBITMAP_TYPE_JPEG);
	backBitmap = new wxBitmap(image);
}

void MainWindow::LoadPlayer()
{
	player = new Spaceship();
}

void MainWindow::LoadMonster(wxTimerEvent &event)
{	
	if (ctrspawnmonster == 5 * level) {
		allowspawn = false;
	}

	addmonster();
	if (ctrkillmonster == 5*level) {
		level++;
		ctrkillmonster = 0;
		ctrspawnmonster = 0;
		allowspawn = true;
	}

	for (int i = monster.size() - 1; i >= 0; i--)
	{
		if (player->isHit(monster[i]->getPositionX(), monster[i]->getPositionY(), monster[i]->getWidth(), monster[i]->getHeight())) {
			player->collide(monster[i]->getDamage());
			ctrkillmonster++;
			monster.erase(monster.begin() + i);
		}
	}
	
	int jummonster = monster.size();

	for (int i = monster.size() - 1; i >=0; i--)
	{
		if (monster[i]->getErase())
		{
			if (monster[i]->getHitground()) {
				player->collide(monster[i]->getDamage());
			}
			else {
				score += monster[i]->getKillpoint();
			}
			ctrkillmonster++;
			monster.erase(monster.begin() + i);
		}
	}

	for (int i = 0; i < monster.size(); i++) {
		monster[i]->move();
	}

	Refresh(false);
}

void MainWindow::addmonster()
{
	int jenis = rand() % 3 + 1;
	if (allowspawn)
	{
		if (jenis == 1)
		{
			SmallMonster *m1 = new SmallMonster((19 * (rand() % 64)) + 75, 50);
			monster.push_back(m1);
		}
		else if (jenis == 2)
		{
			MediumMonster *m1 = new MediumMonster(20 * (rand() % 64), 50);
			monster.push_back(m1);
		}
		else if (jenis == 3)
		{
			LargeMonster *m1 = new LargeMonster(20 * (rand() % 64), 50);
			monster.push_back(m1);
		}
		ctrspawnmonster++;
	}
}

void MainWindow::OnPaint(wxPaintEvent &event)
{
	wxBufferedPaintDC pdc(this);
	if (backBitmap != nullptr)
	{
		pdc.DrawBitmap(*backBitmap, wxPoint(0, 0), true);
		pdc.DrawBitmap(player->getBitmap(), wxPoint(player->getPositionX(), player->getPositionY()), true);
		wxFont font(18, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD); //default-bold
		pdc.SetFont(font);
		pdc.SetTextForeground(*wxWHITE);
		pdc.DrawText(wxString::Format("S C O R E  :  %d ", score), wxPoint(10, 10));
		pdc.DrawText(wxString::Format("M I S S I L E  :  %d ", ctrmissile), wxPoint(10, 30));
		pdc.DrawText(wxString::Format("H P :  %d ", player->getHealth()), wxPoint(600, 10));
		pdc.DrawText(wxString::Format("L E V E L :  %d ", level), wxPoint(1100, 10));
		pdc.SetTextForeground(*wxGREEN);
		pdc.DrawText(wxString::Format("PRESS ESC TO EXIT / PRESS ENTER TO PAUSE"), wxPoint(400, 720));
		for (size_t i = 0; i < monster.size(); i++)
		{
			pdc.DrawBitmap(monster[i]->getBitmap(), wxPoint(monster[i]->getPositionX(), monster[i]->getPositionY()), true);
		}
		for (size_t i = 0; i < bullet.size(); i++)
		{
			pdc.DrawBitmap(bullet[i]->getBitmap(), wxPoint(bullet[i]->getPositionX(), bullet[i]->getPositionY()), true);
		}
	}
}

void MainWindow::OnKeyDown(wxKeyEvent &event)
{
	if (timer->IsRunning() && monsterTimer->IsRunning()) {
		if (event.GetKeyCode() == 'W')
		{
			player->move('W');
		}
		else if (event.GetKeyCode() == 'A')
		{
			player->move('A');
		}
		else if (event.GetKeyCode() == 'S')
		{
			player->move('S');
		}
		else if (event.GetKeyCode() == 'D')
		{
			player->move('D');
		}
		else if (event.GetKeyCode() == ' ' && allowshoot == true)
		{
			allowshoot = false;
			ctrmovebullet = 20;
			GenerateBullet();
		}
		else if (event.GetKeyCode() == 'C' && ctrmissile != 0) {
			GenerateMissile();
			ctrmissile--;
		}
	}
	
	if (event.GetKeyCode() == 27)
	{
		parent->ShowMenuPanel();
	}
	else if (event.GetKeyCode() == 13) {
		if (timer->IsRunning() && monsterTimer->IsRunning()) {
			timer->Stop();
			monsterTimer->Stop();
		}
		else {
			timer->Start(25);
			monsterTimer->Start(75);
		}
	}
	
}

void MainWindow::GenerateBullet()
{
	if(bullet.size() <= 10){
		if (score < 100)
		{
			Bullet* bnew = new NormalBullet(player->getPositionX() + 50, player->getPositionY());
			bullet.push_back(bnew);
		}
		else
		{
			Bullet* bnew = new Laser(player->getPositionX() + 50, player->getPositionY());
			bullet.push_back(bnew);
		}
	}
}

void MainWindow::GenerateMissile()
{
	Bullet* bnew = new Missile(player->getPositionX() + 50, player->getPositionY());
	bullet.push_back(bnew);
}

void MainWindow::OnTimer(wxTimerEvent &event)
{
	if ((rand() % 100) == 7) {
		if (ctrmissile == 0) {
			ctrmissile++;
		}		
	}

	int jumtembak = bullet.size(); 
	ctrmovebullet--;
	
	if (ctrmovebullet == 0)
	{
		allowshoot = true;
	}

    for (int i = 0; i < jumtembak; i++)
	{
		bullet[i]->move();
	}

	for (int i = jumtembak - 1; i >= 0; i--)
	{
		for (int j = monster.size() - 1; j >= 0; j--) {
			if (bullet[i]->isHit(monster[j]->getPositionX(), monster[j]->getPositionY(), monster[j]->getWidth(), monster[j]->getHeight())) {
				monster[j]->attacked(bullet[i]->getDamage());
				if (dynamic_cast<Missile*>(bullet[i]) == nullptr) {
					bullet[i]->setErase();
				}
			}
		}
	}

	for (int i = jumtembak - 1; i >= 0; i--)
	{
		if (bullet[i]->getErase()) {
			bullet.erase(bullet.begin() + i);
		}
	}

	Refresh(false);

	if (player->getHealth() <= 0) {
		hs.add_score(score);
		hs.save_score();
		parent->ShowMenuPanel();
	}
}