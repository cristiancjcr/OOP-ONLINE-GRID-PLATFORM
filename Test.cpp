#include "Test.h"
#include "Question.h"
#include <iostream>
#include <fstream>
#include <sstream>

Test::Test() : score(0), numQuestions(0) {}

void Test::loadQuestions(const std::string& fileName) {
    std::ifstream file(fileName);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        int id;
        std::string type, difficulty, domain, questionText;
        std::vector<std::string> options(4);
        int correctAnswer;

        ss >> id;
        ss.ignore(1, ';');
        std::getline(ss, type, ';');
        std::getline(ss, difficulty, ';');
        std::getline(ss, domain, ';');
        std::getline(ss, questionText, ';');
        for (int i = 0; i < 4; ++i) {
            std::getline(ss, options[i], ';');
        }
        ss >> correctAnswer;

        // Filtrare întrebări în funcție de dificultate și domeniu
        if ((selectedDifficulty == difficulty || selectedDifficulty == "all") &&
            (selectedDomain == domain || selectedDomain == "all")) {
            questions.push_back(Question(id, type, difficulty, domain, questionText, options, correctAnswer));
        }
    }
}


void Test::displayQuestion(const Question& question, int index) {
    std::cout << "Intrebarea " << index + 1 << ": " << question.getQuestionText() << std::endl;

    // Afișează opțiunile de răspuns
    for (int i = 0; i < question.getAnswers().size(); ++i) {
        std::cout << i + 1 << ". " << question.getAnswers()[i] << std::endl;
    }

    // Solicită utilizatorului să aleagă un răspuns
    int answer;
    std::cout << "Alege un răspuns (1-" << question.getAnswers().size() << "): ";
    std::cin >> answer;

    // Verifică dacă răspunsul este corect
    if (question.checkAnswer(answer)) {
        std::cout << "Răspuns corect!" << std::endl;
        score++;
    }
    else {
        // Afișează răspunsul corect
        std::cout << "Răspuns greșit. Răspunsul corect este: "
            << question.getAnswers()[question.getCorrectAnswerIndex() - 1] << std::endl;
    }
}

void Test::startTest() {
    loadQuestions("intrebari.txt");

    // Limita numărului de întrebări la cel disponibil în test
    if (numQuestions > questions.size()) {
        numQuestions = questions.size();
    }

    // Rulăm testul doar cu numărul de întrebări disponibil
    for (size_t i = 0; i < numQuestions; ++i) {
        displayQuestion(questions[i], i);
    }
    displayScore();
}

void Test::displayScore() {
    std::cout << "Scorul tău final este: " << score << "/" << numQuestions << std::endl;
}

// Setează dificultatea
void Test::setDifficulty(const std::string& difficulty) {
    selectedDifficulty = difficulty;
}

// Setează domeniul
void Test::setDomain(const std::string& domain) {
    selectedDomain = domain;
}

// Setează numărul de întrebări
void Test::setNumQuestions(int numQuestions) {
    this->numQuestions = numQuestions;
}

// Returnează întrebările
const std::vector<Question>& Test::getQuestions() const {
    return questions;
}

int Test::getScore() const {
    return score;  // Returnează scorul obținut
}
