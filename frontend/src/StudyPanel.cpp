/**
* @file StudyPanel.cpp
* @brief implementation of the StudyPanel class.
*/

#include "../inc/StudyPanel.h"
#include "../inc/MainFrame.h"
#include "../../backend/inc/StudySession.h"

StudyPanel::StudyPanel(PanelManager* pm, Deck *deck) : RightPanel(pm), session(deck) {
    this->deck = deck;
    this->questionPanel = new wxPanel(this, wxID_ANY, wxPoint(MARGIN, MARGIN),
                                          wxSize(RIGHT_PANEL_SIZE.x - TOP_MARGIN, RIGHT_PANEL_SIZE.y - TOP_MARGIN));
    this->questionPanel->CenterOnParent();
    this->questionPanel->Hide();

    wxPanel* inside_question_panel = new wxPanel(questionPanel, wxID_ANY, wxPoint(2 * MARGIN, TOP_MARGIN),
                                          wxSize(RIGHT_PANEL_SIZE.x - 3 * TOP_MARGIN,
                                                 RIGHT_PANEL_SIZE.y - 3 * TOP_MARGIN));
    inside_question_panel->SetBackgroundColour(wxColour(255, 255, 255));

    question = new wxStaticText(inside_question_panel, wxID_ANY, "pytanie",wxDefaultPosition,wxDefaultSize,wxTEXT_ALIGNMENT_JUSTIFIED);
    question->CenterOnParent();

    wxButton* show_answer_button = new wxButton(questionPanel, wxID_ANY, wxString("Show answer"),wxPoint( 5*MARGIN, 4.5*TOP_MARGIN));
    show_answer_button->Bind(wxEVT_BUTTON,&StudyPanel::ShowAnswerEvent,this);

    this->answerPanel = new wxPanel(this, wxID_ANY, wxPoint(MARGIN, MARGIN),
                                          wxSize(RIGHT_PANEL_SIZE.x - TOP_MARGIN, RIGHT_PANEL_SIZE.y - TOP_MARGIN));
    this->answerPanel->Hide();
    wxPanel* inside_answer_panel = new wxPanel(answerPanel, wxID_ANY, wxPoint(2 * MARGIN, MARGIN),
                                          wxSize(RIGHT_PANEL_SIZE.x - 3 * TOP_MARGIN,
                                                 RIGHT_PANEL_SIZE.y - 3 * TOP_MARGIN));
    inside_answer_panel->SetBackgroundColour(wxColour(255, 255, 255));
    answer = new wxStaticText(inside_answer_panel, wxID_ANY, "answer");
    answer->CenterOnParent();
    wxButton* dont_know_button = new wxButton(this->answerPanel, wxID_ANY, "I don't know", wxPoint(0, 4*TOP_MARGIN));
    wxButton* dont_remember_button = new wxButton(this->answerPanel, wxID_ANY, "I don't remember", wxPoint(2*MARGIN, 4*TOP_MARGIN));
    wxButton* know_something_button = new wxButton(this->answerPanel, wxID_ANY, "I know something", wxPoint( 5*MARGIN, 4*TOP_MARGIN));
    wxButton* know_most = new wxButton(this->answerPanel, wxID_ANY, "I know most", wxPoint(8 * MARGIN, 4*TOP_MARGIN));
    wxButton* know_all_button = new wxButton(this->answerPanel, wxID_ANY, "I know all", wxPoint(10 * MARGIN, 4*TOP_MARGIN));

    dont_know_button->Bind(wxEVT_BUTTON,&StudyPanel::NextQuestionEvent,this, wxID_ANY, wxID_ANY,new ButtonUserData(1));
    dont_remember_button->Bind(wxEVT_BUTTON,&StudyPanel::NextQuestionEvent,this, wxID_ANY, wxID_ANY,new ButtonUserData(2));
    know_something_button->Bind(wxEVT_BUTTON,&StudyPanel::NextQuestionEvent,this, wxID_ANY, wxID_ANY,new ButtonUserData(3));
    know_most->Bind(wxEVT_BUTTON,&StudyPanel::NextQuestionEvent,this, wxID_ANY, wxID_ANY,new ButtonUserData(4));
    know_all_button->Bind(wxEVT_BUTTON,&StudyPanel::NextQuestionEvent,this, wxID_ANY, wxID_ANY,new ButtonUserData(5));

    this->statisticsPanel = new wxPanel(this, wxID_ANY, wxPoint(MARGIN, MARGIN),
                                          wxSize(RIGHT_PANEL_SIZE.x - TOP_MARGIN, RIGHT_PANEL_SIZE.y - TOP_MARGIN));
    this->statisticsPanel->CenterOnParent();
    this->statisticsPanel->Hide();
    wxStaticText* finish_text = new wxStaticText(statisticsPanel, wxID_ANY, "You finished this set! Congratulations");
    finish_text->CenterOnParent();
    wxButton* go_back_button = new wxButton(statisticsPanel, wxID_ANY, "Back", wxPoint(10*MARGIN, 4*TOP_MARGIN));

    go_back_button->Bind(wxEVT_BUTTON,&StudyPanel::GoBackEvent,this);

    session.StartSession();
    ShowNextQuestion();
}

void StudyPanel::ShowNextQuestion() {
    this->answerPanel->Hide();


    this->currentCard = session.GetNextCard();
    if (this->currentCard != nullptr) {
        this->questionPanel->Show();
        this->question->SetLabel(currentCard->GetQuestion());
    }
    else {
        this->statisticsPanel->Show();
    }
}
void StudyPanel::ShowAnswer() {
    this->questionPanel->Hide();
    this->answerPanel->Show();
    if (this->currentCard != nullptr) {
        this->answer->SetLabel(currentCard->GetAnswer());
    }
}
void StudyPanel::ShowAnswerEvent(wxCommandEvent &evt) {
    ShowAnswer();
}
void StudyPanel::NextQuestionEvent(wxCommandEvent &evt) {
    ButtonUserData* answerData = static_cast<ButtonUserData*>(evt.GetEventUserData());
    int lastAnswer = answerData->GetAnswer();
    this->currentCard->AdjustDifficultyAndNextReview(lastAnswer);
    ShowNextQuestion();
}
void StudyPanel::GoBackEvent(wxCommandEvent &evt) {
    this->Hide();
}
