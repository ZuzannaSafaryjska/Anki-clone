/**
* @file App.cpp
* @brief implementation of the App class.
*/

#include "../inc/App.h"
#include "../inc/MainFrame.h"
#include "../inc/PanelManager.h"
#include "../../backend/inc/StorageManager.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    std::string filePath = "data.json";
    storageManager = new StorageManager(filePath);
    allDecks = storageManager->LoadDecks();
    panelManager = new PanelManager(allDecks);
    panelManager->CreateAppWindow();
    return true;
}
int App::OnExit() {
    storageManager->SaveDecks(allDecks);
    delete storageManager;
    delete panelManager;
    for(int i =0; i < allDecks->size(); i++) {
        Deck* deck = allDecks->at(i);
        delete deck;
    }
    delete allDecks;
    return 0;
}
