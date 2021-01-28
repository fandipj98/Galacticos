#pragma once
#include "wx\wx.h"
class MainWindow;
class MainMenu;
class MainHS;

class MainFrame : public wxFrame
{
private:
	wxBoxSizer* boxSizer;
	MainWindow* mainWindow;
	MainMenu* mainMenu;
	MainHS* mainHS;
	int asal;
	void fitWindowSize();
public:
	MainFrame(const wxString &title);
	void InitComponents();
	void ShowMainPanel();
	void ShowHSPanel();
	void ShowMenuPanel();
	~MainFrame();
};