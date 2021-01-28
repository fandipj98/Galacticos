#include "MainHS.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/dcbuffer.h>
#include<iostream>
using namespace std;

BEGIN_EVENT_TABLE(MainHS, wxWindow)
  EVT_LEFT_DOWN(MainHS::OnMouseLeftDown)
  EVT_PAINT(MainHS::OnPaint)
END_EVENT_TABLE()

MainHS::MainHS(MainFrame * parent) :
	wxWindow(parent, wxID_ANY), parentFrame(parent)
{
	wxImageHandler *jpegLoader = new wxJPEGHandler();
	wxImage::AddHandler(jpegLoader);
	wxImage image(wxT("Picture\\hsbaru.jpg"), wxBITMAP_TYPE_JPEG);
	backBitmap = new wxBitmap(image);
	wxImageHandler *pngLoader = new wxPNGHandler();
	wxImage::AddHandler(pngLoader);
	hs = HighScore();
	hs.load_score();
}

void MainHS::OnPaint(wxPaintEvent &event)
{
	wxBufferedPaintDC pdc(this);
	if (backBitmap != nullptr)
	{
		pdc.DrawBitmap(*backBitmap, wxPoint(0, 0), true);
		wxFont font(18, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD); //default-bold
		pdc.SetFont(font);
		pdc.SetTextForeground(*wxWHITE);
		for (int i = 0; i < 5; i++)
		{
			pdc.DrawText(wxString::Format("..>> %d <<..", hs.get_score(i)), wxPoint(632, 275+(70*i)));
		}
	}
}
void MainHS::OnMouseLeftDown(wxMouseEvent &event)
{
	cout << event.GetX()<< event.GetY() << endl;
	wxRect rm(event.GetX(), event.GetY(), 5, 5);
	wxRect rexit(x_menuexit, y_menuexit, w_menu, h_menu);
	if (rm.Intersects(rexit)) {
		parentFrame->ShowMenuPanel();
	}
}
MainHS::~MainHS()
{
	delete backBitmap;
}
