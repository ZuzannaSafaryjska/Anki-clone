/**
* @file MainRightPanel.h
* @brief header file for the MainRightPanel class.
*/

#ifndef MAINRIGHTPANEL_H
#define MAINRIGHTPANEL_H
#include "RightPanel.h"
#include "../../backend/inc/Deck.h"


class MainRightPanel : public RightPanel{
private:
    std::vector<Deck*>* decks;
public:
    /**
     * @brief Constructor of the MainRightPanel class
     *
     * @param pm a pointer to PanelManager
     * @param decks a pointer to a vector of pointers containing all user's decks
     *
     */
    MainRightPanel(PanelManager* pm, std::vector<Deck*>* decks);

    /**
    * @brief Handels the event of clicking on Learn New Button
    *
    * @param evt a reference to a wxCommandEvent object
    */
    void LearnNewButtonEvent(wxCommandEvent &evt);

    /**
    * @brief Handels the event of clicking on Daily Revision Button
    *
    * @param evt a reference to a wxCommandEvent object
    */
    void DailyRevisionButtonEvent(wxCommandEvent &evt);
};



#endif //MAINRIGHTPANEL_H
