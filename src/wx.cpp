#include "wx.hpp"

IMPLEMENT_APP (slApplication);

bool slApplication::OnInit() {
	auto winMain = new slEditor("ScriptLayer");
	winMain->Show(true);
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

	auto help = new wxMenu;
	menubar->Append(help,"&Help");

	help->Append(wxID_ABOUT, "&About\tF1");
	Connect(wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED,
	      wxCommandEventHandler(slEditor::OnAbout));

}

void slEditor::OnQuit(wxCommandEvent& WXUNUSED(event)) { Close(true); }

void slEditor::OnAbout(wxCommandEvent& WXUNUSED(event)) {
	wxMessageBox(TITLE "\n\n(c) " AUTHOR "\n\ngithub: " GITHUB);
}
