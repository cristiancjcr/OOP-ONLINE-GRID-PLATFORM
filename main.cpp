#include "Test.h"
#include <fstream>
#include <iostream>
#include <vector>

int main() {
    std::ifstream inputFile("intrebari.txt");
    std::vector<Question> questions;

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::string text = line;
            std::vector<std::string> options;
            int correctIndex;

            for (int i = 0; i < 4; ++i) {
                std::getline(inputFile, line);
                options.push_back(line);
            }

            inputFile >> correctIndex;
            inputFile.ignore(); // Ignorăm linia goală
            questions.emplace_back(text, options, correctIndex - 1);
        }
    }

    Test test(questions);
    test.shuffleQuestions();
    test.shuffleAnswers();
    test.displayTest();

    return 0;
}
