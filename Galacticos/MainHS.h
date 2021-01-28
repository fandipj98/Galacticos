#pragma once
#include "wx\wx.h"
#include "MainFrame.h"
#include "HighScore.h"

class MainHS : public wxWindow
{
public:
	MainHS(MainFrame* parent);
	void OnPaint(wxPaintEvent &event);
	void OnMouseLeftDown(wxMouseEvent &event);
	~MainHS();
private:
	MainFrame * parentFrame;
	wxBitmap *backBitmap = nullptr;
	int x_menuexit = 512, y_menuexit = 676, w_menu=372, h_menu=49;
	HighScore hs;
	DECLARE_EVENT_TABLE()
};

