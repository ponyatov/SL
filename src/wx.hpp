#ifndef _H_WX
#define _H_WX

#include "hpp.hpp"

#include <wx/wx.h>
#include <wx/stc/stc.h>

class slApplication: public wxApp { public: virtual bool OnInit(); };

class slEditor: public wxFrame {
	wxMenuBar* menubar;
protected:
	wxStyledTextCtrl* editor;
public:
	slEditor(const wxString& title);
	void OnQuit(wxCommandEvent& WXUNUSED(event));
	void OnAbout(wxCommandEvent& WXUNUSED(event));
	void OnStack(wxCommandEvent& WXUNUSED(event));
	void OnVoc(wxCommandEvent& WXUNUSED(event));
	void refresh();
};

class slStack: public slEditor {
public:
	slStack(const wxString& title);
	void refresh();
};

#endif // _H_WX
