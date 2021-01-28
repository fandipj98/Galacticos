#include "wx\wx.h"
#include "MainFrame.h"
class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};
IMPLEMENT_APP(MyApp)
DECLARE_APP(MyApp)
bool MyApp::OnInit()
{
	MainFrame *frame = new MainFrame("Galacticos");
	frame->Show(true);
	return true;
}