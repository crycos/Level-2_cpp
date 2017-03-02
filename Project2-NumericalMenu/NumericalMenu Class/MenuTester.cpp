#include <iostream>
#include "NumericalMenu.h"

using namespace std;

void test0()
{
    NumericalMenu menu;
    menu.setPrompt("Select an option:");
    menu.addOption("Enter new values");
    menu.addOption("Help");
    menu.addOption("Save");
    menu.setCancelText("Exit");

    int result = menu.run();
    cout << endl << "Returned: " << result << endl;
}

/*
Select an option:

1 – Enter new values
2 – Help
3 – Save
4 – Exit

17

Error!

Select an option:

1 – Enter new values
2 – Help
3 – Save
4 – Exit

0

Error!

Select an option:

1 – Enter new values
2 – Help
3 – Save
4 – Exit

4
Returned: -1

*/

void test1()
{
    NumericalMenu menu;

    menu.addOption("Cat");
    menu.addOption("Dog");

    int a = menu.run();

    std::cout << "Return Value is: " << a << std::endl;
}

/*

Choose an option:

1 - Cat
2 - Dog
3 - Cancel

16

Error!

Choose an option:

1 - Cat
2 - Dog
3 - Cancel

2
Return Value is: 2

*/

void test2()
{
    NumericalMenu menu;

    menu.addOption("Cat");
    menu.addOption("Dog");
    menu.addOption("");

    menu.setCancelText("None");

    menu.setPrompt("Choose an animal");
    menu.setErrorText("Wrong!");
    menu.setRepeatPromptOnError(false);

    int result = menu.run();

    std::cout << "The choice was: " << result << std::endl;

    menu.addOption("?");

    std::cout << "Size is " << menu.size() << std::endl;
}

/*

Choose an animal

1 - Cat
2 - Dog
3 - 
4 - None

-1

Wrong!

5

Wrong!

4
The choice was -1
Size is 4

*/

void test3(){
    NumericalMenu menu;

    menu.addOption("Cat");
    menu.addOption("Dog");

    menu.setCancelText("None");

    menu.setPrompt("Choose an animal");
    menu.setErrorText("Wrong!");
    menu.setRepeatPromptOnError(false);

    int result = menu.run();

    std::cout << "The choice was " << result << std::endl;

    while(result != -1){
        result = menu.run();
        std::cout << "\nThe choice was " << result << std::endl;
    }
}

/*

Choose an animal

1 - Cat
2 - Dog
3 - None

2
The choice was 2

Choose an animal

1 - Cat
2 - Dog
3 - None

-1 

Wrong!

1
The choice was 1

Choose an animal

1 - Cat
2 - Dog
3 - None

9

Wrong!

3
The choice was -1

*/

int main()
{
    test0();
    test1();
    test2();
    test3();

    return EXIT_SUCCESS;
}
