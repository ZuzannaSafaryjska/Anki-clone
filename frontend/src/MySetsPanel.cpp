/**
* @file MySetsPanel.cpp
* @brief implementation of the MySetsPanel class.
*/

#include "../inc/MySetsPanel.h"
#include "../inc/MainRightPanel.h"
#include "../inc/PanelManager.h"
#include "../inc/StudyPanel.h"

MySetsPanel::MySetsPanel(PanelManager *pm, std::vector<Deck*>* decks) : RightPanel(pm) {
    this->decks = decks;
    SetupControls();
    SetupSizers();
}

void MySetsPanel::SetupControls() {
    sets_panel = new wxPanel(this, wxID_ANY);

    sets_panel->SetSize(RightPanel::GetSize().x, RightPanel::GetSize().y);
    sets_list = new wxListBox(sets_panel, wxID_ANY);

    back_button = new wxButton(sets_panel, wxID_ANY, wxT("Back"));
    back_button->Bind(wxEVT_BUTTON,&MySetsPanel::BackButtonEvent, this);
    study_button = new wxButton(sets_panel, wxID_ANY, wxT("Study"));
    study_button->Bind(wxEVT_BUTTON,&MySetsPanel::StudyButtonEvent, this);

    remove_button = new wxButton(sets_panel, wxID_ANY, wxT("Remove"), wxPoint(10.5*MARGIN,TOP_MARGIN/2), wxSize(-1,-1));
    remove_button->Bind(wxEVT_BUTTON,&MySetsPanel::RemoveButtonEvent, this);

    headline = new wxStaticText(sets_panel, wxID_ANY, wxT("Your Sets"));
    headline->SetSize(wxSize(wxDefaultCoord,32));

    for (int i = 0; i < decks->size(); i++) {
        wxString name = static_cast<wxString>(decks->at(i)->GetName());
        sets_list->Append(name);
    }
}

void MySetsPanel::SetupSizers() {
    auto* mainSizer = new wxBoxSizer(wxVERTICAL);
    auto* buttonGrid = new wxBoxSizer(wxHORIZONTAL);
    mainSizer->Add(headline,0,wxALIGN_CENTER|wxALL,10);
    mainSizer->Add(sets_list,1,wxEXPAND|wxLEFT | wxRIGHT,200);
    buttonGrid->Add(back_button,0,wxALIGN_CENTER|wxALL,10);
    buttonGrid->Add(study_button,0,wxALIGN_CENTER|wxALL,10);
    mainSizer->Add(buttonGrid,0,wxALIGN_CENTER|wxALL,10);
    sets_panel->SetSizer(mainSizer);
    sets_panel->Layout();
}

void MySetsPanel::StudyButtonEvent(wxCommandEvent &evt) {
    if(sets_list->GetSelection() != wxNOT_FOUND) {
        int index = sets_list->GetSelection();
        this->Hide();
        StudyPanel* study_panel = new StudyPanel(this->GetPanelManager(),decks->at(index));
    }
}
void MySetsPanel::BackButtonEvent(wxCommandEvent &evt) {
    this->Hide();
    MainRightPanel* main_panel = new MainRightPanel(this->GetPanelManager(),decks);
}
void MySetsPanel::RemoveButtonEvent(wxCommandEvent &evt) {
    if(sets_list->GetSelection() != wxNOT_FOUND) {
        int index = sets_list->GetSelection();
        sets_list->Delete(sets_list->GetSelection());
        Deck* deck = decks->at(index);
        decks->erase(decks->begin() + index);
        delete deck;
    }
}


