#include "MainMenu.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/dcbuffer.h>

BEGIN_EVENT_TABLE(MainMenu, wxWindow)
  EVT_LEFT_DOWN(MainMenu::OnMouseLeftDown)
  EVT_PAINT(MainMenu::OnPaint)
END_EVENT_TABLE()

MainMenu::MainMenu(MainFrame * parent) :
	wxWindow(parent, wxID_ANY), parentFrame(parent)
{
	wxImageHandler *jpegLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpegLoader);
	wxImage image(wxT("Picture\\mainmenu.jpg"), wxBITMAP_TYPE_JPEG);
	backBitmap = new wxBitmap(image);
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);
	wxImage imageplay(wxT("Picture\\play.png"), wxBITMAP_TYPE_PNG);
	playBitmap = new wxBitmap(imageplay);
	wxImage imagehs(wxT("Picture\\hs.png"), wxBITMAP_TYPE_PNG);
	hsBitmap = new wxBitmap(imagehs);
	wxImage imageexit(wxT("Picture\\exit.png"), wxBITMAP_TYPE_PNG);
	exitBitmap = new wxBitmap(imageexit);
}

void MainMenu::OnPaint(wxPaintEvent &event)
{
	wxBufferedPaintDC pdc(this);
	if (backBitmap != nullptr)
	{
		pdc.DrawBitmap(*backBitmap, wxPoint(0, 0), true);
		pdc.DrawBitmap(*playBitmap, wxPoint(x_menuplay, y_menuplay), true);
		pdc.DrawBitmap(*hsBitmap, wxPoint(x_menuhs, y_menuhs), true);
		pdc.DrawBitmap(*exitBitmap, wxPoint(x_menuexit, y_menuexit), true);
	}
}

void MainMenu::OnMouseLeftDown(wxMouseEvent &event) 
{ 
	wxRect rm(event.GetX(), event.GetY(), 5, 5);
	wxRect rplay(x_menuplay, y_menuplay, w_menu, h_menu);
	wxRect rhs(x_menuhs, y_menuhs, w_menu, h_menu);
	wxRect rexit(x_menuexit, y_menuexit, w_menu, h_menu);
	if (rm.Intersects(rplay))
	{
		parentFrame->ShowMainPanel();
	}
	if (rm.Intersects(rhs))
	{
		parentFrame->ShowHSPanel();
	}
	else if (rm.Intersects(rexit)) {
		exit(0);
	}
}


MainMenu::~MainMenu()
{
	delete backBitmap;
	delete playBitmap;
	delete hsBitmap;
	delete exitBitmap;
}
