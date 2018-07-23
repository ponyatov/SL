#include "wx.hpp"

IMPLEMENT_APP (wxScriptLayer);

bool wxScriptLayer::OnInit() {
	auto winMain = new wxFrame(NULL, wxID_ANY, "ScriptLayer");
	winMain->Show(true);

	auto menubar = new wxMenuBar;
	winMain->SetMenuBar(menubar);

	return true;
}
