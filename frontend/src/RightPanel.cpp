/**
* @file RightPanel.cpp
* @brief implementation of the RightPanel class.
*/

#include "../inc/RightPanel.h"
#include "../inc/PanelManager.h"

RightPanel::RightPanel(PanelManager* pm) : wxPanel(pm->GetMainFrame(), wxID_ANY,RIGHT_PANEL_POS, RIGHT_PANEL_SIZE, wxBORDER_SIMPLE) {
    this->panelManager = pm;
    this->SetBackgroundColour(wxColor(238, 201, 210));
}
PanelManager* RightPanel::GetPanelManager() {
    return this->panelManager;
}