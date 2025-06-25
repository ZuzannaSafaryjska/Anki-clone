/**
* @file MainRightPanel.cpp
* @brief implementation of the MainRightPanel class.
*/

#include "../inc/MainRightPanel.h"
#include "../inc/PanelManager.h"
#include <random>
#include "../inc/StudyPanel.h"
#include "../../backend/inc/StudySession.h"


MainRightPanel::MainRightPanel(PanelManager *pm, std::vector<Deck*>* decks) : RightPanel(pm){
    this->decks = decks;

    wxStaticText* study_text = new wxStaticText(this, wxID_ANY, "Study", wxPoint(MARGIN,MARGIN), wxSize(MARGIN,MARGIN));
    study_text->SetFont(this->headline_font);

    wxPanel* daily_revision_button_panel = new wxPanel(this, wxID_ANY, wxPoint(MARGIN,2*MARGIN), wxSize(MARGIN+TOP_MARGIN,TOP_MARGIN),wxBORDER_SIMPLE);
    daily_revision_button_panel->SetBackgroundColour(wxColor(255, 255, 255));
    wxButton* daily_revision_button = new wxButton(daily_revision_button_panel, wxID_ANY, wxT("Daily revision"));
    daily_revision_button->Center();
    daily_revision_button->Bind(wxEVT_BUTTON, &MainRightPanel::LearnNewButtonEvent,this);

    wxPanel* learn_new_button_panel = new wxPanel(this, wxID_ANY, wxPoint(MARGIN+MARGIN+TOP_MARGIN+MARGIN,2*MARGIN), wxSize(MARGIN+TOP_MARGIN,TOP_MARGIN),wxBORDER_SIMPLE);
    learn_new_button_panel->SetBackgroundColour(wxColor(255, 255, 255));
    wxButton* learn_new_button = new wxButton(learn_new_button_panel, wxID_ANY, wxT("Learn something new"));
    learn_new_button->Center();
    learn_new_button->Bind(wxEVT_BUTTON,&MainRightPanel::LearnNewButtonEvent,this);

    wxStaticText* last_used_text = new wxStaticText(this, wxID_ANY, "Last used", wxPoint(MARGIN,6*MARGIN), wxSize(MARGIN,MARGIN));
    last_used_text->SetFont(this->headline_font);

    for (int i = 0; i < decks->size() ; i++) {
        Deck* deck = decks->at(i);
        if(i > 2)
            break;
        wxButton* button = new wxButton(this, wxID_ANY, deck->GetName(), wxPoint(MARGIN,(8+i)*MARGIN));
        DeckUserData* deckData = new DeckUserData(deck, pm);
        button->Bind(wxEVT_BUTTON, &(PanelManager::StartStudySessionEvent),wxID_ANY,wxID_ANY,deckData);
    }
}
void MainRightPanel::LearnNewButtonEvent(wxCommandEvent &evt) {
    if (decks->size() > 0) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(0, decks->size()-1);
        StudyPanel* study_panel = new StudyPanel(this->GetPanelManager(), decks->at(distr(gen)));
    }
}
void::MainRightPanel::DailyRevisionButtonEvent(wxCommandEvent &evt) {
    if (decks->size() > 0) {
        std::vector<Flashcard*>* dueCards;
        for(auto deck : *this->decks) {}
    }
}

