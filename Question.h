#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

class Question {
private:
    std::string questionText;
    std::vector<std::string> options;
    int correctAnswerIndex;  // Indexul răspunsului corect în lista de opțiuni
    int userAnswer;          // Răspunsul utilizatorului (-1 dacă nu a răspuns)

public:
    // Constructor
    Question(std::string text, std::vector<std::string> opts, int correctIndex);

    // Accesori pentru opțiuni
    const std::vector<std::string>& getOptions() const;
    void setOptions(const std::vector<std::string>& newOptions);

    // Accesori pentru răspuns corect
    int getCorrectAnswerIndex() const;
    void setCorrectAnswerIndex(int index);
    std::string getCorrectAnswerOption() const;

    // Interfața de lucru cu întrebarea
    void displayQuestion(int number) const;
    void setUserAnswer(int answer);
    bool evaluateAnswer() const;
};

#endif