/**
* @file MainFrame.h
* @brief header file for the MainFrame class.
*/

#ifndef MAINFRAME_H
#define MAINFRAME_H
#include <wx/wx.h>
#include "RightPanel.h"
#include "PanelManager.h"

class MainFrame : public wxFrame {
    PanelManager* pm;
    public:
    /**
     * @brief Constructor of the MainFrame class
     *
     * @param pm a pointer to PanelManager
     * @param title a reference to a wxString containing the title
     */
    MainFrame(PanelManager* pm, const wxString& title);
    /**
     * @brief Creates the panel that is present in the left side of the window
     *
     * @param pm a pointer to PanelManager
     *
     */
    void CreateLeftPanel(PanelManager* pm);

    /**
     * @brief Handels the event of clicking on My Sets Button
     *
     * @param evt a reference to a wxCommandEvent object
     */
    void OnMySetsButtonClicked(wxCommandEvent &evt);

private:
    /**
     * @brief Handels the event of clicking on Create New Button
     *
     * @param evt a reference to a wxCommandEvent object
     */
    void OnCreateNewButtonClicked(wxCommandEvent& evt);
};



#endif //MAINFRAME_H
