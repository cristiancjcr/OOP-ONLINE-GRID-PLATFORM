#include "Question.h"

// Constructor pentru întrebări
Question::Question(int id, const std::string& type, const std::string& difficulty, const std::string& domain,
    const std::string& questionText, const std::vector<std::string>& options, int correctAnswer)
    : id(id), type(type), difficulty(difficulty), domain(domain), questionText(questionText), options(options), correctAnswer(correctAnswer) {
}

// Funcție pentru a verifica răspunsul
bool Question::checkAnswer(int answer) const {
    // Verifică dacă răspunsul este corect
    return answer == correctAnswer;
}

// Funcție pentru a obține textul întrebării
std::string Question::getQuestionText() const {
    return questionText; // Returnează textul întrebării
}

// Funcție pentru a obține opțiunile de răspuns
std::vector<std::string> Question::getAnswers() const {
    return options; // Returnează opțiunile de răspuns
}

// Funcție pentru a obține indexul răspunsului corect
int Question::getCorrectAnswerIndex() const {
    return correctAnswer; // Returnează indexul răspunsului corect
}
