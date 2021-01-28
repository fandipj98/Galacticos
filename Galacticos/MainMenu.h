#pragma once
#include "wx\wx.h"
#include "MainFrame.h"

class MainMenu: public wxWindow
{
public:
	MainMenu(MainFrame* parent);
	void OnPaint(wxPaintEvent &event);
	void OnMouseLeftDown(wxMouseEvent &event);
	~MainMenu();
private:
	MainFrame * parentFrame;
	wxBitmap *backBitmap = nullptr;
	wxBitmap *playBitmap = nullptr;
	wxBitmap *hsBitmap = nullptr;
	wxBitmap *exitBitmap = nullptr;
	int x_menuplay = 540, y_menuplay = 300;
	int x_menuhs = 550, y_menuhs = 400;
	int x_menuexit = 550, y_menuexit = 500;
	int w_menu = 300, h_menu = 80;
	DECLARE_EVENT_TABLE()
};

