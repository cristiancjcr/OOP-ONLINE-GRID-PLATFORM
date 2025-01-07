#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

class Question {
private:
    int id; // ID-ul întrebării
    std::string type; // Tipul întrebării (ex: Single, Multiple)
    std::string difficulty; // Dificultatea întrebării
    std::string domain; // Domeniul întrebării (ex: Matematica, Istorie)
    std::string questionText; // Textul întrebării
    std::vector<std::string> options; // Opțiunile de răspuns
    int correctAnswer; // Indexul răspunsului corect (1-based)

public:
    // Constructor pentru întrebări
    Question(int id, const std::string& type, const std::string& difficulty, const std::string& domain,
        const std::string& questionText, const std::vector<std::string>& options, int correctAnswer);

    // Funcție pentru a verifica răspunsul
    bool checkAnswer(int answer) const;

    // Funcție pentru a obține textul întrebării
    std::string getQuestionText() const;

    // Funcție pentru a obține opțiunile de răspuns
    std::vector<std::string> getAnswers() const;

    // Funcție pentru a obține indexul răspunsului corect
    int getCorrectAnswerIndex() const;
};

#endif // QUESTION_H
