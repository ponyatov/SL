#include "wx.hpp"

IMPLEMENT_APP(slApplication);

slEditor* wnEditor = NULL;
slEditor*  wnStack = NULL;
slEditor*    wnVoc = NULL;

bool slApplication::OnInit() {
	wnEditor = new slEditor("ScriptLayer:Editor");
	wnEditor->Show(true);
	wnStack = new slEditor("ScriptLayer:Stack");
//	wnStack->Show(true);
	wnVoc = new slEditor("ScriptLayer:Vocabulary");
//	wnVoc->Show(true);
	return true;
}

slEditor::slEditor(const wxString& title): wxFrame(NULL, wxID_ANY, title) {

	auto menubar = new wxMenuBar;
	SetMenuBar(menubar);

	auto file = new wxMenu;
	menubar->Append(file,"&File");

	file->Append(wxID_EXIT, "&Quit");
	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED,
	      wxCommandEventHandler(slEditor::OnQuit));

	auto edit = new wxMenu;
	menubar->Append(edit,"&Edit");
	edit->Append(wxID_UNDO, "&Undo\tCtrl-Z");

	CreateStatusBar(1);

	auto win = new wxMenu;
	menubar->Append(win,"&Window");
	win->Append(wxID_REFRESH, "&Refresh\tF12");

	win->Append(wxID_TOP, "&Stack\tF8");
	Connect(wxID_TOP, wxEVT_COMMAND_MENU_SELECTED,
	      wxCommandEventHandler(slEditor::OnStack));
	win->Append(wxID_INDEX, "&Vocabulary\tF9");
	Connect(wxID_INDEX, wxEVT_COMMAND_MENU_SELECTED,
	      wxCommandEventHandler(slEditor::OnVoc));

	auto help = new wxMenu;
	menubar->Append(help,"&Help");

	help->Append(wxID_ABOUT, "&About\tF1");
	Connect(wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED,
	      wxCommandEventHandler(slEditor::OnAbout));

	auto editor = new wxTextCtrl(this,wxID_ANY,"# comment",\
			wxDefaultPosition,wxDefaultSize,\
				wxTE_MULTILINE);


}

void slEditor::OnQuit(wxCommandEvent& WXUNUSED(event)) {
	wnEditor->Close(true);
	wnStack->Close(true);
	wnVoc->Close(true);
}

void slEditor::OnAbout(wxCommandEvent& WXUNUSED(event)) {
	wxMessageBox(TITLE "\n\n(c) " AUTHOR "\n\ngithub: " GITHUB);
}

void slEditor::OnStack(wxCommandEvent& WXUNUSED(event)) {
	wnStack->Show(true);
}

void slEditor::OnVoc(wxCommandEvent& WXUNUSED(event)) {
	wnVoc->Show(true);
}
