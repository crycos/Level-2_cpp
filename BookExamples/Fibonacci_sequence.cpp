#include <iostream>
using namespace std;

/* Output the Fibonacci sequence step-by-step.
   Fibonacci sequence starts as:
   0 1 1 2 3 5 8 13 21 ... in which the first
   two numbers are 0 and 1 and each additional
   number is the sum of the previous two numbers
*/

void ComputeFibonacci(int fibNum1, int fibNum2, int runCnt) {
   
   cout << fibNum1 << " + " << fibNum2 << " = "
        << fibNum1 + fibNum2 << endl;
   
   if (runCnt <= 1) { // Base case: Ran for user specified
                      // number of steps, do nothing
   }
   else {            // Recursive case: compute next value
      ComputeFibonacci(fibNum2, fibNum1 + fibNum2, runCnt - 1);
   }
   
   return;
}

int main() {
   int runFor = 0; // User specified number of values computed
   
   // Output program description
   cout << "This program outputs the" << endl
   << "Fibonacci sequence step-by-step," << endl
   << "starting after the first 0 and 1." << endl << endl;
   
   // Prompt user for number of values to compute
   cout << "How many steps would you like? ";
   cin >> runFor;
   
   // Output first two Fibonacci values, call recursive function
   cout << "0" << endl << "1" << endl;
   ComputeFibonacci(0, 1, runFor);
   
   return 0;
}
