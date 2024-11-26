#include "Test.h"
#include <algorithm>
#include <random>
#include <iostream>

// Constructor
Test::Test(std::vector<Question> qs) : questions(qs) {}

// Shuffle pentru întrebări
void Test::shuffleQuestions() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(questions.begin(), questions.end(), g);
}

// Shuffle pentru opțiuni
void Test::shuffleAnswers() {
    std::random_device rd;
    std::mt19937 g(rd());
    for (auto& question : questions) {
        int correctIndex = question.getCorrectAnswerIndex();
        std::vector<std::string> opts = question.getOptions();

        // Amestecăm opțiunile
        std::shuffle(opts.begin(), opts.end(), g);

        // Determinăm noul index al răspunsului corect
        int newCorrectIndex = std::distance(opts.begin(), std::find(opts.begin(), opts.end(), question.getCorrectAnswerOption()));

        question.setOptions(opts);
        question.setCorrectAnswerIndex(newCorrectIndex);
    }
}

// Afișează testul și permite răspunsul
void Test::displayTest() {
    int questionNumber = 1;
    for (auto& question : questions) { // 'auto&' pentru a modifica întrebările
        question.displayQuestion(questionNumber);

        int userAnswer;
        std::cin >> userAnswer;

        while (userAnswer < 1 || userAnswer > question.getOptions().size()) {
            std::cout << "Răspuns invalid! Alege între 1 și " << question.getOptions().size() << ": ";
            std::cin >> userAnswer;
        }

        question.setUserAnswer(userAnswer); // Acum este permis
        if (question.evaluateAnswer()) {
            std::cout << "Răspuns corect!\n";
        }
        else {
            std::cout << "Răspuns greșit! Corect era: " << question.getCorrectAnswerOption() << "\n";
        }

        ++questionNumber;
    }
}

// Evaluează scorul utilizatorului
int Test::evaluateAnswers() const {
    int score = 0;
    for (const auto& question : questions) {
        if (question.evaluateAnswer()) {
            ++score;
        }
    }
    return score;
}
