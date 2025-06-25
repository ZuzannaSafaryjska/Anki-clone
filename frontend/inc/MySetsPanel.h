/**
* @file MySetsPanel.h
* @brief header file for the MySetsPanel class.
*/

#ifndef MYSETSPANEL_H
#define MYSETSPANEL_H
#include "MainFrame.h"


class MySetsPanel : public RightPanel {
public:

    /**
     * @brief Constructor of the MySetsPanel class
     *
     * @param pm a pointer to Panel Manager
     * @param decks a pointer to a vector of pointers containing all user's decks
     */
    MySetsPanel(PanelManager* pm,std::vector<Deck*>* decks);

    /**
    * @brief Handels the event of clicking on Study Button
    *
    * @param evt a reference to a wxCommandEvent object
    */
    void StudyButtonEvent(wxCommandEvent &evt);

    /**
    * @brief Handels the event of clicking on Back Button
    *
    * @param evt a reference to a wxCommandEvent object
    */
    void BackButtonEvent(wxCommandEvent &evt);

    /**
    * @brief Handels the event of clicking on Remove Button
    *
    * @param evt a reference to a wxCommandEvent object
    */
    void RemoveButtonEvent(wxCommandEvent &evt);

    void SetupControls();
    void BindControls();
    void SetupSizers();
private:
    std::vector<Deck*>* decks;
    wxPanel* sets_panel;
    wxListBox* sets_list;
    wxButton* study_button;
    wxButton* back_button;
    wxButton* remove_button;
    wxButton* closeButton = new wxButton(sets_panel, wxID_ANY, wxT("Close"));
    wxStaticText* headline;
};




#endif //MYSETSPANEL_H
