/**
* @file Deck.h
* @brief header file for the Deck class.
*/
#ifndef DECK_H
#define DECK_H

#include <string>
#include "Flashcard.h"
#include <vector>


class Deck {
    std::string name;
    std::vector<Flashcard*>* cards;
public:
    /**
     * @brief Constructor of the Deck class
     *
     * @param name a const reference to a string containing the name of the deck
     *
     * @return errorCode if any error occurs, 0 otherwise
     */
    explicit Deck(std::string const& name);

    /**
     * @brief Destructor of the Deck class
     */
    ~Deck();

    /**
     * @brief Adds a card to deck
     *
     * @param a pointer to the flashcard that is to be added
     */
    void AddCard(Flashcard* card);

    /**
     * @brief Removes deck
     */
    void RemoveDeck();

    std::string GetName() const;
    std::vector<Flashcard*>* GetCards() const;
    void SetName(std::string const& name);

     /**
     * @brief Gets the due cards of a specyfic deck
     *
     * @return vector of indexes of due cards
     */
    std::vector<int> GetDueCardsIndexes() const;
};
#endif //DECK_H
