#include <iostream>
using namespace std;

class CarCounter {
   public:
      CarCounter();
      CarCounter& operator=(const CarCounter& objToCopy);
      void SetCarCount(const int setVal) {
         carCount = setVal;
      }
      int GetCarCount() const {
         return carCount;
      }
   private:
      int carCount;
};

CarCounter::CarCounter() {
   carCount = 0;
   return;
}

// FIXME write copy assignment operator

/* Your solution goes here  */
CarCounter& CarCounter::operator=(const CarCounter& objToCopy) {
    if (this != &objToCopy) 
    carCount = objToCopy.carCount; 
    return *this;
}
/* Solution Ends */

int main() {
   CarCounter frontParkingLot;
   CarCounter backParkingLot;

   frontParkingLot.SetCarCount(12);
   backParkingLot = frontParkingLot;

   cout << "Cars counted: " << backParkingLot.GetCarCount();

   return 0;
}
