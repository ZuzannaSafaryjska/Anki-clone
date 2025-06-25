/**
* @file Flashcard.cpp
* @brief implementation of the Flashcard class.
*/
#include <iostream>
#include "../inc/Flashcard.h"
#include "../inc/Utilities.h"


Flashcard::Flashcard(const std::string &question, const std::string &answer) {
        this->id = Utilities::GenerateId();
        this->question = question;
        this->answer = answer;
        this->difficulty = 5;
        this->nextReview = 0;
    };
Flashcard::Flashcard(Flashcard &other) {
    this->id = other.id;
    this->question = other.question;
    this->answer = other.answer;
    this->difficulty = other.difficulty;
    this->nextReview = other.nextReview;
};
Flashcard::Flashcard(Flashcard const &other) {
    this->id = other.id;
    this->question = other.question;
    this->answer = other.answer;
    this->difficulty = other.difficulty;
    this->nextReview = other.nextReview;
};
Flashcard::~Flashcard() {};
    int Flashcard::AdjustDifficultyAndNextReview(int lastAnswer) {
        switch (lastAnswer) {
            case 1:
                this->difficulty -= 2;
                this->nextReview = std::time(nullptr) + 5*(Utilities::MINUTE_S);
            break;
            case 2:
                this->difficulty -= 1;
                this->nextReview = std::time(nullptr) + (Utilities::HOUR_S);
            break;
            case 3:
                this->difficulty += 0;
                this->nextReview = std::time(nullptr) + 5 * (Utilities::HOUR_S);
            break;
            case 4:
                this->difficulty +=1;
                this->nextReview = std::time(nullptr) + (Utilities::DAY_S);
            break;
            case 5:
                this->difficulty += 2;
                this->nextReview = std::time(nullptr) + 3*(Utilities::DAY_S);
            break;
            default:
                return 1;
        }
        if (this->difficulty < 0) {
            this->difficulty = 0;
        }
        else if (this->difficulty > 5) {
            this->difficulty = 5;
        }
        return 0;
    };

    int Flashcard::GetId() const {
        return this->id;
    };

    std::string Flashcard::GetQuestion() const {
        return this->question;
    };

    std::string Flashcard::GetAnswer() const {
        return this->answer;
    };

    int Flashcard::GetDifficulty() const {
        return this->difficulty;
    };


    time_t Flashcard::GetNextReview() const {
        return this->nextReview;
    }

    void Flashcard::SetId(int id) {
        this->id = id;
    };
    void Flashcard::SetQuestion(std::string const& question) {
        this->question = question;
    };
    void Flashcard::SetAnswer(std::string const& answer) {
        this->answer = answer;
    };
    void Flashcard::SetDifficulty(int difficulty) {
        if (difficulty < 0) {
            this->difficulty = 0;
        }
        else if (difficulty > 5) {
            this->difficulty = 5;
        }
        else {
            this->difficulty = difficulty;
        }
    };
    void Flashcard::SetNextReview(time_t nextReview) {
        this->nextReview = nextReview;
    };
    //inkrementacja postfix prefix tak aby bylo to zwiekszenie trudnosci o 1
    //prefix
    Flashcard& Flashcard::operator++() {
        int dif = this->GetDifficulty();
        this->SetDifficulty(dif+1);
        return *this;
    };
    //postfix
    Flashcard Flashcard::operator++(int) {
        Flashcard temp = *this;
        ++(*this);
        return temp;
    }


    Flashcard &Flashcard::operator=(const Flashcard &other) {
        if (this == &other)
            return *this;

        this->id = other.id;
        this->question = other.question;
        this->answer = other.answer;
        this->difficulty = other.difficulty;
        this->nextReview = other.nextReview;

        return *this;
    }




