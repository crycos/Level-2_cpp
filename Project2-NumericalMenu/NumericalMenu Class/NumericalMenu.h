#ifndef NUMERICAL_H
#define NUMERICAL_H

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class NumericalMenu {
public:
    NumericalMenu();
    int addOption(string option);
    void setCancelText (string cancelText);
    void setErrorText (string errorText);
    void setPrompt(string prompt);
    void setRepeatPromptOnError(bool shouldRepeat);
    int run() const;
    int size() const;
private:
    vector<string> menuOption;
    string cancelMessage, errorMessage, promptMessage;
    bool promptRepeat;
    int assignedNumber;
};

#endif