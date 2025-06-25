/**
* @file StorageManager.h
* @brief header file for the StorageManager class.
*/

#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include <string>
#include "Deck.h"
#include "StudySession.h"
#include <vector>
#include "json.hpp"
using json = nlohmann::json;

class StorageManager {
    std::string filePath;

    public:
    /**
     * @brief Constructor of the StorageManager class
     *
     * @param filePath a const reference to a string containing the file path
     */
    explicit StorageManager(std::string const& filePath);

    /**
     * @brief Reads the data from a text file and loads the deck to a vector of pointers to decks
     *
     * @return pointer to a vector of pointers to decks
     */
    std::vector<Deck*>* LoadDecks();

    /**
     * @brief Saves the decks to a text file
     *
     * @param decks a const pointer to a vector of pointers containing all user's decks
     */
    void SaveDecks(const std::vector<Deck*>* decks) const;


    static json SerializeFlashcard(const Flashcard* flashcard) ;
    static json SerializeDeck(const Deck* deck);
    static void DeserializeFlashcard(json const& j,Flashcard* flashcard);
    static void DeserializeDeck(json const& j,Deck* deck);
};








#endif //STORAGEMANAGER_H
