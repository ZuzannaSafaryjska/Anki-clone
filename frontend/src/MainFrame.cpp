/**
* @file MainFrame.cpp
* @brief implementation of the MainFrame class.
*/


#include "../inc/MainFrame.h"
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <__filesystem/operations.h>
#include "../inc/MySetsPanel.h"
#include "../inc/RightPanel.h"
#include "../inc/PanelManager.h"
#include "../inc/CreateNewPanel.h"
#include "../inc/App.h"
#include <wx/filename.h>


MainFrame::MainFrame(PanelManager* pm, const wxString &title) : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)) {
    this->SetBackgroundColour(wxColour(238, 227, 231));
    this->pm = pm;
    this->SetClientSize(MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT);
    this->Center();
    CreateLeftPanel(pm);
}
void MainFrame::CreateLeftPanel(PanelManager* pm) {
    wxInitAllImageHandlers();
    wxImage* logo = new wxImage(wxFileName::GetCwd() + wxFileName::GetPathSeparator() + "../frontend/fishes.png", wxBITMAP_TYPE_PNG, -1);

    wxBitmap* logoBitmap = new wxBitmap(*logo);
    wxStaticBitmap* logo_map = new wxStaticBitmap(this, wxID_ANY, *logoBitmap, wxPoint(2*MARGIN - 20, MARGIN), wxSize(300, 100));
    

    wxPanel* left_panel = new wxPanel(this, wxID_ANY, LEFT_PANEL_POS, LEFT_PANEL_SIZE, wxBORDER_SIMPLE);
    left_panel->SetBackgroundColour(wxColor(234, 213, 220));

    wxPanel* my_sets_button_panel = new wxPanel(left_panel, wxID_ANY, wxPoint(MARGIN,MARGIN), wxSize(250,200),wxBORDER_SIMPLE);
    my_sets_button_panel->SetBackgroundColour(wxColor(255, 255, 255));
    wxButton* my_sets_button = new wxButton(my_sets_button_panel, wxID_ANY, "My sets");
    my_sets_button->CenterOnParent();
    my_sets_button->Bind(wxEVT_BUTTON, &MainFrame::OnMySetsButtonClicked, this);

    wxPanel* create_new_button_panel=  new wxPanel(left_panel, wxID_ANY, wxPoint(50,300), wxSize(250,200),wxBORDER_SIMPLE);
    create_new_button_panel->SetBackgroundColour(wxColor(255, 255, 255));
    wxButton* create_new_button = new wxButton(create_new_button_panel, wxID_ANY, "Create new");
    create_new_button->CenterOnParent();
    create_new_button->Bind(wxEVT_BUTTON,&MainFrame::OnCreateNewButtonClicked,this);
}
void MainFrame::OnMySetsButtonClicked(wxCommandEvent &evt) {
    MySetsPanel* mySetsPanel = new MySetsPanel(this->pm, pm->GetDecks());
}
void MainFrame::OnCreateNewButtonClicked(wxCommandEvent &evt) {
    wxPanel* createNewPanel = new CreateNewPanel(this->pm);
}