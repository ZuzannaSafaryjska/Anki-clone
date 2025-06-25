/**
* @file StudyPanel.h
* @brief header file for the StudyPanel class.
*/

#ifndef STUDYPANEL_H
#define STUDYPANEL_H
#include "RightPanel.h"
#include "../../backend/inc/Deck.h"
#include "MainFrame.h"
#include "../../backend/inc/StudySession.h"


class StudyPanel : public RightPanel {
private:
    Deck* deck;
    StudySession session;
    Flashcard* currentCard;
    wxStaticText* question;
    wxStaticText* answer;
    wxPanel* questionPanel;
    wxPanel* answerPanel;
    wxPanel* statisticsPanel;

public:
    /**
     * @brief Constructor of the MainRightPanel class
     *
     * @param pm a pointer to PanelManager
     * @param deck a pointer to a deck that is to be studied
     *
     */
    StudyPanel(PanelManager* pm, Deck* deck);

    /**
     * @brief Shows next question in current deck
     *
     */
    void ShowNextQuestion();

    /**
    * @brief Handels the event of clicking on Next Question Button
    *
    * @param evt a reference to a wxCommandEvent object
    */
    void NextQuestionEvent(wxCommandEvent &evt);

    /**
    * @brief Shows next answer in current deck
    *
    */
    void ShowAnswer();

    /**
    * @brief Handels the event of clicking on Show Answer Button
    *
    * @param evt a reference to a wxCommandEvent object
    */
    void ShowAnswerEvent(wxCommandEvent &evt);

    /**
    * @brief Handels the event of clicking on Go Back Button
    *
    * @param evt a reference to a wxCommandEvent object
    */
    void GoBackEvent(wxCommandEvent &evt);
};


class ButtonUserData : public wxObject {
private:
    int answer;
    PanelManager* pm;
public:
    ButtonUserData(int answer) : wxObject(){
        this->answer = answer;
    }
    int GetAnswer() {
        return this->answer;
    }
};
#endif //STUDYPANEL_H
