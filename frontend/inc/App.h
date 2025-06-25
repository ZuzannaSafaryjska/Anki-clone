/**
* @file App.h
* @brief header file for the App class
*/

#ifndef APP_H
#define APP_H
#include <wx/wx.h>

#include "../../backend/inc/StorageManager.h"
#include "PanelManager.h"

class App : public wxApp {
private:
    std::vector<Deck*>* allDecks;
    PanelManager* panelManager;
    StorageManager* storageManager;
public:
    /**
     * @brief Initializes the creation of the main window and the structures necessary to starting the application
     *
     * @return true
     */
    bool OnInit();

    StorageManager* GetStorageManager() { return storageManager; }
    std::vector<Deck*>* GetAllDecks() { return allDecks; }

    /**
     * @brief Frees up occupied space
     *
     * @return 0
     */
    int OnExit();
};

#endif //APP_H
