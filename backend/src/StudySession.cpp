/**
* @file StudySession.cpp
* @brief implementation of the StudySession class.
*/
#include "../inc/StudySession.h"

#include <iostream>
#include <ostream>

StudySession::StudySession(Deck *deck): deck(deck){
    this->deck = deck;
    this->currentFlashcardIndexesIndex = -1;
}
void StudySession::StartSession() {
    std::vector<int> dueCardsIndexes = this->deck->GetDueCardsIndexes();
    std::vector<Flashcard*>* const& allCards = this->deck->GetCards();
    this->flashcardsIndexes.insert(flashcardsIndexes.end(), dueCardsIndexes.begin(), dueCardsIndexes.end());
    for (int i = 0; i < allCards->size(); i++) {
        if(std::find(dueCardsIndexes.begin(), dueCardsIndexes.end(), i) == dueCardsIndexes.end()){
            flashcardsIndexes.push_back(i);
        }
    }
    if(flashcardsIndexes.size() > 0) {
        currentFlashcardIndexesIndex = 0;
    }
}
Flashcard* StudySession::GetNextCard() {
    if ((currentFlashcardIndexesIndex == -1) || (currentFlashcardIndexesIndex >= flashcardsIndexes.size())) {
        return nullptr;
    }
    int currentCardIndex = flashcardsIndexes.at(currentFlashcardIndexesIndex);
    Flashcard* nextCard = deck->GetCards()->at(currentCardIndex);
    currentFlashcardIndexesIndex++;
    return nextCard;
}
StudySession::~StudySession() {

}






