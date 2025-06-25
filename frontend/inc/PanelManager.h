/**
* @file PanelManager.h
* @brief header file for the PanelManager class.
*/

#ifndef PANELMANAGER_H
#define PANELMANAGER_H

#include <wx/wx.h>
#include "../../backend/inc/Deck.h"


class PanelManager {
public:
    /**
     * @brief Constructor of the PanelManager class
     *
     * @param decks a pointer to a vector of pointers containing all user's decks
     *
     */
    PanelManager(std::vector<Deck*>* decks) {
        main = nullptr;
        this->decks = decks;
    };

    /**
     * @brief Creates the app window
     *
     */
    void CreateAppWindow();

    /**
     * @brief Creates the Main Right Panel
     */
    void CreateMainRightPanel();

    /**
     * @brief Creates the Study Panel
     *
     * @param deck a pointer to the deck that is to be studied
     *
     */
    void CreateStudyPanel(Deck* deck);

    /**
    * @brief Handels the event of clicking on Start Study Session Button
    *
    * @param evt a reference to a wxCommandEvent object
    */
    static void StartStudySessionEvent(wxCommandEvent &evt);

    wxFrame* GetMainFrame();
    std::vector<Deck*>* GetDecks();
private:
    wxFrame* main;
    std::vector<Deck*>* decks;
};

class DeckUserData : public wxObject {
private:
    Deck* deck;
    PanelManager* pm;
public:
    DeckUserData(Deck* deck, PanelManager* pm) : wxObject(){
        this->deck = deck;
        this->pm = pm;
    }
    Deck* GetDeck() {
        return this->deck;
    }

    PanelManager* GetPanelManager() {
        return this->pm;
    }
};


static constexpr int TOP_MARGIN = 100;
static constexpr int BOTTOM_MARGIN = 100;
static constexpr int MARGIN = 50;
static constexpr int LEFT_PANEL_WIDTH = 350;
static constexpr int MAIN_WINDOW_WIDTH = 1200;
static constexpr int MAIN_WINDOW_HEIGHT = 800;

static const wxSize MAIN_WINDOW_SIZE{MAIN_WINDOW_WIDTH, MAIN_WINDOW_HEIGHT};
static const wxPoint LEFT_PANEL_POS{MARGIN, TOP_MARGIN+MARGIN};
static const wxSize LEFT_PANEL_SIZE{LEFT_PANEL_WIDTH, MAIN_WINDOW_SIZE.y - TOP_MARGIN - MARGIN - BOTTOM_MARGIN};
static const wxPoint RIGHT_PANEL_POS{LEFT_PANEL_POS.x +LEFT_PANEL_SIZE.x + MARGIN, TOP_MARGIN};
static const wxSize RIGHT_PANEL_SIZE{MAIN_WINDOW_SIZE.x - 2*MARGIN - LEFT_PANEL_SIZE.x - LEFT_PANEL_POS.x, MAIN_WINDOW_SIZE.y - TOP_MARGIN - BOTTOM_MARGIN};

#endif //PANELMANAGER_H
