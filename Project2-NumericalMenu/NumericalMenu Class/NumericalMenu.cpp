#include <iostream>
#include "NumericalMenu.h"
using namespace std;

/* Default constructor */
NumericalMenu::NumericalMenu() {
    promptMessage = "Choose an option:";
    cancelMessage = "Cancel";
    errorMessage = "Error!";
    promptRepeat = true;
    assignedNumber = 0;
}
/* Add the passed in option to the menu. Returns the number assigned to the new option in the menu*/
int NumericalMenu::addOption(string option) {
    menuOption.push_back(option);
    assignedNumber++;
    return assignedNumber;
}
/* Set the text displayed for cancellation to cancelText. (Defaults to "Cancel" if not called.) */
void NumericalMenu::setCancelText(string cancelText) {
    cancelMessage = cancelText;
}
/* Set the text displayed on receipt of invalid input to errorText. (Defaults to "Error!" if not called. */
void NumericalMenu::setErrorText(string errorText) {
    errorMessage = errorText;
}
/*Set the initial prompt that precedes the menu options. (Defaults to "Choose an option:") */
void NumericalMenu::setPrompt(string prompt) {
    promptMessage = prompt;
}
/* Set whether or not the prompt is repeated on receipt of invalid input; prompt will be repeated if shouldRepeat is true. (Defaults to true if not called.) */
void NumericalMenu::setRepeatPromptOnError(bool shouldRepeat) {
    promptRepeat = shouldRepeat;
}
/* Runs the menu; does not return until the user provides valid input. Returns -1 on cancellation, and the option number otherwise. */
int NumericalMenu::run() const {
    cout << promptMessage << endl << endl;
    for (int i = 0; i < size(); i++) {
        cout << i + 1 << " - " << menuOption.at(i) << endl;
    }
    int setOption = this ->size();
    int enteredOption;
    cout << setOption + 1 << " - " << cancelMessage << endl << endl;
    while(!(cin >> enteredOption) || enteredOption <= 0  || enteredOption > (setOption + 1)) {
        if(promptRepeat != 0) {
            cout << errorMessage << endl << endl;
        } else {
            cout << errorMessage << endl << endl;
            cout << promptMessage << endl << endl;
            for (int i = 1; i <= setOption; i++) {
                cout << i << " - " << menuOption.at(i - 1) << endl << endl;
            }
            cout << setOption + 1 << " - " << cancelMessage << endl << endl;
        }
    }
    if(enteredOption == (setOption + 1)) {
        return -1;
    } else {
        return enteredOption;
    }
}

/* Returns the current number of menu options in this menu. */
int NumericalMenu::size() const {
    return assignedNumber;
}


int main()
{
NumericalMenu menu;
menu.setPrompt("Select an option:");
menu.addOption("Enter new values");
menu.addOption("Help");
menu.addOption("Save");
menu.setCancelText("Exit");
int result = menu.run();
cout << "Returned: " << result << endl;
}