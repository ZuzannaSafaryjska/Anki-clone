/**
* @file Deck.cpp
* @brief implementation of the Deck class.
*/
#include "../inc/Flashcard.h"
#include "../inc/Utilities.h"
#include "../inc/Deck.h"

#include <iostream>
#include <ostream>
#include <vector>

Deck::Deck(std::string const& name) {
    this->name = name;
    this->cards = new std::vector<Flashcard*>;
    Utilities::numberOfDecks++;
}
Deck::~Deck() {
    for(int i = 0; i < this->cards->size(); i++) {
        Flashcard* card = this->cards->at(i);
        delete card;
    }
    delete this->cards;
}
void Deck::AddCard(Flashcard* card) {
    this->cards->push_back(card);
};
void Deck::RemoveDeck() {
    if(Utilities::numberOfDecks > 0) {
        Utilities::numberOfDecks--;
    }
}
std::vector<int> Deck::GetDueCardsIndexes() const {
    std::vector<int> dueCardsIndexes;
    for(int i = 0; i < this->cards->size(); i++) {
        Flashcard* card = this->cards->at(i);
        if (card->GetNextReview() > std::time(nullptr)) {
            dueCardsIndexes.push_back(i);
        }
    }
    return dueCardsIndexes;
};
std::vector<Flashcard*>* Deck::GetCards() const {
    return this->cards;
}
std::string Deck::GetName() const {
    return this->name;
}
void Deck::SetName(std::string const &name) {
    this->name = name;
}



