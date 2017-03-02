#include <iostream>
using namespace std;

template<typename TheType>
TheType TripleMin(TheType item1, TheType item2, TheType item3) {
   TheType minVal = item1; // Holds min item value, init to first item
   
   if (item2 < minVal) {
      minVal = item2;
   }
   if (item3 < minVal) {
      minVal = item3;
   }
   
   return minVal;
}

int main() {
   int num1 = 55;
   int num2 = 99;
   int num3 = 66;
   int dbl1 = 12;
   
   cout << "Items: " << num1 << " " << num2 << " " << num3 << endl;
   cout << "Min: " << TripleMin(num1, num2, num3) << endl << endl;
   
   cout << "Items: " << dbl1 << " " << num2 << " " << num3 << endl;
   cout << "Min: " << TripleMin(dbl1, num2, num3) << endl << endl;
      
   return 0;
}

