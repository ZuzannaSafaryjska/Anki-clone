/**
* @file StorageManager.cpp
* @brief implementation of the StorageManager class.
*/

#include "../inc/StorageManager.h"
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include "../inc/json.hpp"
using json = nlohmann::json;


StorageManager::StorageManager(std::string const& filePath) {
    this->filePath = filePath;
}


std::vector<Deck*>* StorageManager::LoadDecks() {
    std::ifstream file(this->filePath);
    if (!file.is_open()) {
        std::cout<<"file is not open for reading"<<std::endl;
    }
    json j;
    if (file.peek() == std::ifstream::traits_type::eof()) {
        j = nlohmann::json::object();
        std::vector<Deck*>* decks = new std::vector<Deck*>();
        return decks;
    } else {
        try {
            file >> j;
        } catch (const json::parse_error& e) {
            file.close();
            throw std::runtime_error("Invalid JSON format: " + std::string(e.what()));
        }
    }
    file.close();

    auto* decks = new std::vector<Deck*>();
    if (!j.is_array()) {
        delete decks;
        throw std::runtime_error("JSON is not an array");
    }

    for (const auto& deck_json : j) {
        Deck* deck = new Deck(std::string("deck"));
        DeserializeDeck(deck_json, deck);
        decks->push_back(deck);

    }

    return decks;
}

void StorageManager::SaveDecks(const std::vector<Deck*>* decks) const {
    if (decks == nullptr) {
        //exe
        std::cerr << "Saving decks failed!" << std::endl;
    }
    else {
        json j = json::array();
        for (auto const& deck : *decks) {
            j.push_back(SerializeDeck(deck));
        }
        std::ofstream outfile(this->filePath);
        if (!outfile.is_open()) {
            std::cerr << "Failed to open file!" << std::endl;
        }
        outfile << j.dump(4);
        outfile.close();
    }
}

json StorageManager::SerializeFlashcard(const Flashcard* flashcard) {
    json j;
    j["id"] = flashcard->GetId();
    j["question"] = flashcard->GetQuestion();
    j["answer"] = flashcard->GetAnswer();
    j["difficulty"] = flashcard->GetDifficulty();
    j["nextReview"] = flashcard->GetNextReview();
    return j;
}
json StorageManager::SerializeDeck(const Deck* deck) {
    json j;
    j["name"] = deck->GetName();
    if (!deck->GetCards()->empty()) {
        j["cards"] = json::array();
        for (const auto& card : *deck->GetCards()) {
            j["cards"].push_back(SerializeFlashcard(card));
        }
    } else {
        j["cards"] = json::array();
    }
    return j;
}

void StorageManager::DeserializeFlashcard(json const& j,Flashcard* flashcard) {
    flashcard->SetId(j.at("id").get<int>());
    flashcard->SetQuestion(j.at("question").get<std::string>());
    flashcard->SetAnswer(j.at("answer").get<std::string>());
    flashcard->SetDifficulty(j.at("difficulty").get<int>());
    flashcard->SetNextReview(j.at("nextReview").get<time_t>());
}

void StorageManager::DeserializeDeck(json const &j, Deck* deck) {
    if(j.contains("name")) {
        deck->SetName(j.at("name").get<std::string>());
    }
    if (j.contains("cards") && j["cards"].is_array()) {
        for (const auto& jsonCard : j["cards"]) {
            auto card = new Flashcard(" "," ");
            DeserializeFlashcard(jsonCard,card);
            deck->AddCard(card);
        }
    }
}

