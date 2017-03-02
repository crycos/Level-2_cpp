#include <iostream>
#include <string>
using namespace std;

static int permutationCount = 0;

void PermuteString(string head, string tail) {
   char current = '?';
   string newPermute = "";
   int len = 0;
   int i = 0;

   len = tail.length();
   if (len <= 1) {
      ++permutationCount;
      cout << permutationCount << ") " << head + tail << endl;
   }
   else {
      for (i = len - 1; i >= 0; --i) {
         current = tail[i];           // Get next leading character
         newPermute = tail.substr(0, i) + tail.substr(i + 1);
                                      // Get the rest of the tail
         PermuteString(head + current, newPermute);
      } 
   }

   return;
} 

int main() {
   const string PROMPT_STRING = "Enter a string to permute (<Enter> to exit): ";
   string input = "";

   // Get input and permute the string
   cout << PROMPT_STRING << endl;
   cin >> input;

   while (input.length() > 0) {
      permutationCount = 0;
      PermuteString("", input);
      cout << PROMPT_STRING << endl;
      input = "";
      cin >> input;
   } 
   cout << "Done." << endl;

   return 0;
} 
