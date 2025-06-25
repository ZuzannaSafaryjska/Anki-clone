/**
* @file CreateNewPanel.h
* @brief header file for the CreateNewPanel class.
*/

#ifndef CREATENEWPANEL_H
#define CREATENEWPANEL_H
#include "RightPanel.h"



class CreateNewPanel : public RightPanel{
private:
    Deck* deck;
    std::vector<Deck*>* decks;
    wxTextCtrl* name;
    wxTextCtrl* question;
    wxTextCtrl* answer;

public:
    /**
     * @brief Constructor of the CreateNewPanel class
     *
     * @param panelManager a pointer to Panel Manager
     *
     */
    CreateNewPanel(PanelManager* panelManager);

    /**
    * @brief Handels the event of clicking on Save Deck Button
    *
    * @param evt a reference to a wxCommandEvent object
    */
    void SaveDeckButtonEvent(wxCommandEvent &evt);

    /**
    * @brief Handels the event of clicking on Next Flashcard Button
    *
    * @param evt a reference to a wxCommandEvent object
    */
    void NextFlashcardButtonEvent(wxCommandEvent &evt);

    /**
    * @brief Handels the event of clicking on Back Button
    *
    * @param evt a reference to a wxCommandEvent object
    */
    void BackButtonEvent(wxCommandEvent &evt);

    /**
     * @brief Saves created flashcard
     *
     */
    void SaveFlashcard();
};

#endif //CREATENEWPANEL_H
