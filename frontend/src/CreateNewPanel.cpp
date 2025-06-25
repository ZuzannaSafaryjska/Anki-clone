/**
* @file CreateNewPanel.cpp
* @brief implementation of the CreateNewPanel class.
*/

#include "../inc/CreateNewPanel.h"
#include "../inc/StudyPanel.h"
#include "../../backend/inc/StudySession.h"

CreateNewPanel::CreateNewPanel(PanelManager* pm): RightPanel(pm){
    deck = new Deck("");
    decks = pm->GetDecks();

    wxStaticText* text = new wxStaticText(this, wxID_ANY, wxT("Create New Panel"));

    wxPanel* namePanel = new wxPanel(this, wxID_ANY, wxPoint(MARGIN, MARGIN), wxSize(5*TOP_MARGIN, MARGIN), wxBORDER_SIMPLE);
    namePanel->SetBackgroundColour(wxColour(255,255,255));
    wxStaticText* name_label = new wxStaticText(namePanel, wxID_ANY, wxT("Deck name:"), wxDefaultPosition);
    name = new wxTextCtrl(namePanel, wxID_ANY, wxT(""), wxPoint(TOP_MARGIN,-1), wxSize(5*TOP_MARGIN, -1),wxBORDER_NONE);
    name->Centre();


    wxPanel* flashCardPanel = new wxPanel(this, wxID_ANY, wxPoint(2 * MARGIN, TOP_MARGIN),
                                          wxSize(RIGHT_PANEL_SIZE.x - 3 * TOP_MARGIN,
                                                 RIGHT_PANEL_SIZE.y - 3 * TOP_MARGIN), wxBORDER_SIMPLE);
    flashCardPanel->CenterOnParent();
    flashCardPanel->SetBackgroundColour(wxColour(255,255,255));

    wxStaticText* question_label = new wxStaticText(flashCardPanel, wxID_ANY, wxT("Question: "),wxPoint(0, TOP_MARGIN), wxDefaultSize);
    question = new wxTextCtrl(flashCardPanel, wxID_ANY, wxT(""), wxPoint(1.5*MARGIN, TOP_MARGIN), wxSize(RIGHT_PANEL_SIZE.x - 3 * TOP_MARGIN - 1.5*MARGIN, -1),wxBORDER_SIMPLE);
    name->Centre();

    wxStaticText* answer_label = new wxStaticText(flashCardPanel, wxID_ANY, wxT("Answer: "),wxPoint(0, 2*TOP_MARGIN), wxDefaultSize);
    answer = new wxTextCtrl(flashCardPanel, wxID_ANY, wxT(""), wxPoint(1.5*MARGIN, 2*TOP_MARGIN), wxSize(RIGHT_PANEL_SIZE.x - 3 * TOP_MARGIN- 1.5*MARGIN, -1),wxBORDER_SIMPLE);
    name->Centre();

    wxButton* next = new wxButton(this, wxID_ANY, wxT("Next"), wxPoint(5*TOP_MARGIN, 5*TOP_MARGIN));
    wxButton* save = new wxButton(this, wxID_ANY, wxT("Save"), wxPoint(4*TOP_MARGIN, 5*TOP_MARGIN));
    next->Bind(wxEVT_BUTTON,&CreateNewPanel::NextFlashcardButtonEvent, this);
    save->Bind(wxEVT_BUTTON,&CreateNewPanel::SaveDeckButtonEvent, this);

    wxButton* back = new wxButton(this, wxID_ANY, wxT("Back"), wxPoint(TOP_MARGIN, 5*TOP_MARGIN));
    back->Bind(wxEVT_BUTTON,&CreateNewPanel::BackButtonEvent, this);


}
void CreateNewPanel::NextFlashcardButtonEvent(wxCommandEvent &evt) {
    SaveFlashcard();
};
void CreateNewPanel::SaveFlashcard() {
    if ((question->GetValue() != "") && (answer->GetValue() != "")) {
        Flashcard* flashcard = new Flashcard(static_cast<std::string>(question->GetValue()), static_cast<std::string>(answer->GetValue()));
        deck->AddCard(flashcard);
        question->Clear();
        answer->Clear();
    } else {
        wxMessageBox("Flashcard must have question and answer");
    }
}
void CreateNewPanel::SaveDeckButtonEvent(wxCommandEvent &evt) {
    SaveFlashcard();
    if (name->GetValue() != "") {
        deck->SetName(static_cast<std::string>(name->GetValue()));
        decks->push_back(deck);
        this->Hide();
        this->GetPanelManager()->CreateMainRightPanel();
    } else {
        wxMessageBox("Provide deck title");
    }
};
void CreateNewPanel::BackButtonEvent(wxCommandEvent &evt) {
    this->Hide();
}
