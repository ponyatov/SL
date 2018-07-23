#ifndef _H_WX
#define _H_WX

#include "hpp.hpp"

#include <wx/wx.h>
class slApplication: public wxApp { public: virtual bool OnInit(); };

class slEditor: public wxFrame {
public:
	slEditor(const wxString& title);
	void OnQuit(wxCommandEvent& WXUNUSED(event));
	void OnAbout(wxCommandEvent& WXUNUSED(event));

};

#endif // _H_WX
