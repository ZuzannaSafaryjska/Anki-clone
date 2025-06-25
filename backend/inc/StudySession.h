/**
* @file StudySession.h
* @brief header file for the StudySession class.
*/
#ifndef STUDYSESSION_H
#define STUDYSESSION_H

#include "Flashcard.h"
#include "Deck.h"


class StudySession {
    Deck* deck;
    std::vector<int> flashcardsIndexes;
    int currentFlashcardIndexesIndex;
public:
    /**
     * @brief Constructor of the StudySession class
     *
     * @param deck a reference to the Deck that is to be studied
     */
    StudySession(Deck* deck);
    void SetCurrentCardIndex();
    void StartSession();
    Flashcard* GetNextCard();
    /**
     * @brief Destructor of the Deck class
     */
    ~StudySession();
};
#endif //STUDYSESSION_H
