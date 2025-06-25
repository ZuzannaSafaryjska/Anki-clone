/**
* @file RightPanel.h
* @brief header file for the RightPanel class.
*/

#ifndef RIGHTPANEL_H
#define RIGHTPANEL_H
#include <wx/generic/panelg.h>
#include "PanelManager.h"
#include <wx/wx.h>
#include <wx/panel.h>


class RightPanel : public wxPanel {
private:
    PanelManager* panelManager;
public:
    wxFont headline_font = wxFont(wxFontInfo(wxSize(0,32)).Bold());

    /**
     * @brief Constructor of the RightPabel class
     *
     * @param pm a pointer to PanelManager
     *
     */
    RightPanel(PanelManager* pm);
    PanelManager* GetPanelManager();
};


#endif //RIGHTPANEL_H
