#include <iostream>
using namespace std;

void BackwardsAlphabet(char currLetter){
   if (currLetter == 'a') {
      cout << currLetter << endl;
   }
   else{
      cout << currLetter << " ";
      BackwardsAlphabet(currLetter - 1);
   }
   return;
}

int main() {
   char startingLetter = '-';

   startingLetter = 'z';

   /* Your solution goes here  */
   BackwardsAlphabet(startingLetter);   

   return 0;
}
