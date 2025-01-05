#ifndef TEST_H
#define TEST_H

#include <vector>
#include <string>
#include "Question.h"

class Test {
private:
    std::vector<Question> questions;       // Lista de întrebări
    int score;                             // Scorul obținut
    std::string selectedDifficulty;        // Dificultatea selectată
    std::string selectedDomain;            // Domeniul selectat
    int numQuestions;                      // Numarul de întrebări dorit de utilizator

public:
    Test();                                // Constructor
    void loadQuestions(const std::string& fileName);   // Încarcă întrebările dintr-un fișier
    void startTest();                      // Începe testul
    void displayQuestion(const Question& question, int index); // Afișează o întrebare
    void displayScore();                   // Afișează scorul final

    // Setează dificultatea testului
    void setDifficulty(const std::string& difficulty);

    // Setează domeniul întrebărilor
    void setDomain(const std::string& domain);

    // Setează numărul de întrebări
    void setNumQuestions(int numQuestions);

    // Funcția pentru obținerea întrebărilor (pentru a fi folosită pentru validări)
    const std::vector<Question>& getQuestions() const;

    // Funcția pentru obținerea scorului
    int getScore() const;  // Adăugat pentru a obține scorul
};

#endif // TEST_H
