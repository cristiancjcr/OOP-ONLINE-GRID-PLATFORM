#include "Test.h"
#include "Question.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

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

    // Salvăm scorul utilizatorului
    saveUserScore();

    // Afișăm scorul final
    displayScore();
}

void Test::displayScore() {
    // Citim scorurile anterioare pentru utilizator
    std::ifstream scoresFile("scores.txt");
    std::map<std::string, int> userTotalScore;
    std::map<std::string, int> userTotalQuestions;

    std::string line;

    // Citim scorurile și le adăugăm în map
    while (std::getline(scoresFile, line)) {
        std::stringstream ss(line);
        std::string user;
        int score, totalQuestions;
        char delimiter;

        std::getline(ss, user, ':');
        ss >> score;
        ss.ignore(1);  // Ignorăm caracterul '/'
        ss >> totalQuestions;

        userTotalScore[user] += score;          // Adunăm scorurile pentru fiecare utilizator
        userTotalQuestions[user] += totalQuestions; // Adunăm totalul întrebărilor pentru fiecare utilizator
    }

    // Afișăm rezultatul final pentru utilizatorul curent
    std::cout << "Scorul tău final este: " << username << ": "
        << userTotalScore[username] << "/"
        << userTotalQuestions[username] << std::endl;
}


void Test::saveUserScore() {
    std::cout << "Introdu numele utilizatorului: ";
    std::cin >> username;  // Numele utilizatorului

    // Salvăm scorul curent al utilizatorului într-o linie separată
    std::ofstream scoresFile("scores.txt", std::ios::app);  // Folosim std::ios::app pentru a adăuga la fișier
    if (scoresFile.is_open()) {
        // Salvăm scorul curent într-o linie separată
        scoresFile << username << ": " << score << "/" << numQuestions << std::endl;
    }
    else {
        std::cerr << "Nu s-a putut deschide fișierul scores.txt!" << std::endl;
    }
}


void Test::displayLeaderboard() {
    std::ifstream scoresFile("scores.txt");
    std::map<std::string, std::pair<int, int>> userScores;  // Corectarea declarației
    std::string line;

    // Citim scorurile și le adăugăm în map
    while (std::getline(scoresFile, line)) {
        std::stringstream ss(line);
        std::string user;
        int score, totalQuestions;
        char delimiter;

        std::getline(ss, user, ':');
        ss >> score;
        ss.ignore(1);  // Ignorăm caracterul '/'
        ss >> totalQuestions;

        userScores[user].first += score;          // Suma scorurilor
        userScores[user].second += totalQuestions; // Suma întrebărilor
    }

    // Sortăm utilizatorii în funcție de scor
    std::vector<std::pair<std::string, std::pair<int, int>>> leaderboard(userScores.begin(), userScores.end());
    std::sort(leaderboard.begin(), leaderboard.end(), [](const std::pair<std::string, std::pair<int, int>>& a, const std::pair<std::string, std::pair<int, int>>& b) {
        return a.second.first > b.second.first;  // Sortăm după scor
        });

    // Afișăm clasamentul
    std::cout << "\nClasament:\n";
    for (const auto& entry : leaderboard) {
        std::cout << entry.first << ": " << entry.second.first << "/" << entry.second.second << " puncte\n";
    }
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
