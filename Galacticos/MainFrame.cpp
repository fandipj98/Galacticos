#include "MainFrame.h"
#include "MainWindow.h"
#include "MainMenu.h"
#include "MainHS.h"

MainFrame::MainFrame(const wxString &title)
	: wxFrame(NULL, wxID_ANY, title)
{
	//this->window = new MainWindow(this);
	//this->SetInitialSize(wxSize(1366, 768));
	//this->ShowFullScreen(true);
	this->InitComponents();
}

void MainFrame::InitComponents()
{
	boxSizer = new wxBoxSizer(wxVERTICAL);
	asal = 0;
	this->mainMenu = new MainMenu(this);
	this->boxSizer->Add(mainMenu, 1, wxEXPAND, 0);
	SetSizer(boxSizer);
	fitWindowSize();
}

void MainFrame::ShowHSPanel()
{
	this->mainMenu->Destroy();
	asal = 1;
	this->mainHS = new MainHS(this);
	this->boxSizer->Add(mainHS, 1, wxEXPAND, 0);
	SetSizer(boxSizer);
	fitWindowSize();
}

void MainFrame::ShowMainPanel()
{
	this->mainMenu->Destroy();
	asal = 2;
	this->mainWindow = new MainWindow(this);
	this->boxSizer->Add(mainWindow, 1, wxEXPAND, 0);
	SetSizer(boxSizer);
	fitWindowSize();
}

void MainFrame::ShowMenuPanel()
{
	if (asal==0)
	{ 
		this->mainMenu->Destroy();
	}
	else if (asal==2)
	{
		this->mainWindow->Destroy();
	}
	else if (asal==1)
	{
		this->mainHS->Destroy();
	}
	this->mainMenu = new MainMenu(this);
	this->boxSizer->Add(mainMenu, 1, wxEXPAND, 0);
	SetSizer(boxSizer);
	fitWindowSize();
}

void MainFrame::fitWindowSize()
{
	this->boxSizer->Fit(this);
	this->boxSizer->SetSizeHints(this);
	this->SetSize(wxSize(1366, 768));
	this->Layout();
	this->ShowFullScreen(true);
}

MainFrame::~MainFrame()
{
}
