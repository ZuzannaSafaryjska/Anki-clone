/**
* @file Flashcard.h
* @brief header file for the Flashcard class.
*/
#ifndef FLASHCARD_H
#define FLASHCARD_H
#include <string>

class Flashcard {
    int id;
    std::string question;
    std::string answer;
    int difficulty; //scale 1-5
    time_t nextReview;

public:
     /**
     * @brief Constructor of the Flashcard class
     *
     * @param question a reference to a string containing the question
     * @param answer a reference to a string containing the answer
     * @param keyPath a path to a file containing the encryption key
     *
     */
    Flashcard(const std::string &question, const std::string &answer);
    /**
     * @brief Copy constructor of the Flashcard class
     *
     * @param question a reference to a string containing the question
     * @param answer a reference to a string containing the answer
     * @param keyPath a path to a file containing the encryption key
     *
     */
    Flashcard(Flashcard &other);
    /**
     * @brief Const copy constructor of the Flashcard class
     *
     * @param question a reference to a string containing the question
     * @param answer a reference to a string containing the answer
     * @param keyPath a path to a file containing the encryption key
     *
     */
    Flashcard(Flashcard const &other);
    /**
     * @brief Destructor of the Flashcard class
     */
    ~Flashcard();

    /**
    * @brief Ajusts the difficulty and next review fields in a specyfic flashcard
    *
    * @param lastAnswer the last anwswer provided by user
    *
    * @return 1 if any error occurs, 0 otherwise
    */
    int AdjustDifficultyAndNextReview(int lastAnswer);

    int GetId() const;
    std::string GetQuestion() const;
    std::string GetAnswer() const;
    int GetDifficulty() const;
    time_t GetNextReview() const;
    void SetId(int id);
    void SetQuestion(std::string const& question);
    void SetAnswer(std::string const& answer);
    void SetDifficulty(int difficulty);
    void SetNextReview(time_t nextReview);
    Flashcard& operator=(const Flashcard& other);
    Flashcard& operator++();
    Flashcard operator++(int);
};




#endif //FLASHCARD_H
