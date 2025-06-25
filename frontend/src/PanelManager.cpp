/**
* @file PanelManager.cpp
* @brief implementation of the PanelManager class.
*/
#include "../inc/MainFrame.h"
#include "../inc/PanelManager.h"
#include "../inc/MainRightPanel.h"
#include "../inc/StudyPanel.h"


void PanelManager::CreateAppWindow() {
    MainFrame* mainFrame = new MainFrame(this, "Fishes");
    this->main = mainFrame;
    CreateMainRightPanel();
    mainFrame->Show();
}
void PanelManager::CreateMainRightPanel() {
    RightPanel* right_panel = new MainRightPanel(this, this->decks);
    right_panel->Show();
}
wxFrame* PanelManager::GetMainFrame() {
    return this->main;
}

void PanelManager::StartStudySessionEvent(wxCommandEvent &evt) {
    DeckUserData* deckData = static_cast<DeckUserData*>(evt.GetEventUserData());
    Deck* currentDeck = deckData->GetDeck();
    StudyPanel* studyPanel = new StudyPanel(deckData->GetPanelManager(), currentDeck);
    studyPanel->Show();
    //to-do: del deckuserdata
}
std::vector<Deck*>* PanelManager::GetDecks() {
    return this->decks;
};