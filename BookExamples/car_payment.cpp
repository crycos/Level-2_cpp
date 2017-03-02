#include <iostream>
#include <string>
using namespace std;

class myClass {
    public:
        void downPay() {
        cout << "Enter down payment: " << endl;
        cint >> downPay;
        }
        void mPay() {
        cout << "Enter monthly payments: " << endl;
        cint >> mPay;
        }
        void total() {
        int total;
            return downPay + mPay * 12; 
        }

};
int main() {
    myClass totalDeal;
    totalDeal.downPay();
    totalDeal.mPay();
    cout << total << endl;
    return 0;
}


