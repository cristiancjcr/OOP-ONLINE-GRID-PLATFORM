#ifndef TEST_H
#define TEST_H

#include "Question.h"
#include <vector>

class Test {
private:
    std::vector<Question> questions;

public:
    Test(std::vector<Question> qs);

    void shuffleQuestions();
    void shuffleAnswers();
    void displayTest();
    int evaluateAnswers() const;
};

#endif