#include <iostream>
using namespace std;

class CarCounter {
   public:
      CarCounter();
      ~CarCounter();
   private:
      int carCount;
};

CarCounter::CarCounter() {
   carCount = 0;
   return;
}

// Write a destructor for the CarCounter class that outputs the following. End with newline.
/* Your solution goes here  */
CarCounter::~CarCounter() {
   cout << "Destroying CarCounter" << endl;
}
/* Solution Ends */

int main() {
   CarCounter* parkingLot = new CarCounter();
   delete parkingLot;
   return 0;
}
