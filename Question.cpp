#include "Question.h"
#include <iostream>
#include <algorithm>

// Constructor
Question::Question(std::string text, std::vector<std::string> opts, int correctIndex)
    : questionText(text), options(opts), correctAnswerIndex(correctIndex), userAnswer(-1) {
}

// Getter pentru opțiuni
const std::vector<std::string>& Question::getOptions() const {
    return options;
}

// Setter pentru opțiuni
void Question::setOptions(const std::vector<std::string>& newOptions) {
    options = newOptions;
}

// Getter pentru indexul răspunsului corect
int Question::getCorrectAnswerIndex() const {
    return correctAnswerIndex;
}

// Setter pentru indexul răspunsului corect
void Question::setCorrectAnswerIndex(int index) {
    correctAnswerIndex = index;
}

// Obține opțiunea corectă (string-ul corespunzător)
std::string Question::getCorrectAnswerOption() const {
    return options[correctAnswerIndex];
}

// Afișează întrebarea și opțiunile
void Question::displayQuestion(int number) const {
    std::cout << number << ". " << questionText << "\n";
    for (size_t i = 0; i < options.size(); ++i) {
        std::cout << "  " << i + 1 << ". " << options[i] << "\n";
    }
}

// Setează răspunsul utilizatorului
void Question::setUserAnswer(int answer) {
    userAnswer = answer - 1; // Ajustăm la index bazat pe 0
}

// Evaluează răspunsul utilizatorului
bool Question::evaluateAnswer() const {
    return userAnswer == correctAnswerIndex;
}
