#include<iostream>
using namespace std;


long long getNumber();
bool isValid(long long);
int sumOfDoubleEvenPlace(long long);
int getDigit(int);
int sumOfOddPlace(long long);
bool prefixMatched(long long, int);
int getSize(long long);
int getPrefix(long long, int);

/* Input from user */
long long getNumber() {
    long long number;
    cin >> number;
    return number;
}

/* Boolean operator for credit card number*/
bool isValid(long long number) {
    int numSize = getSize(number);
    if (numSize > 16 || numSize < 13) return false;
    int sum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
    if (sum % 10 != 0) return false;
    if (prefixMatched(number, 4)) return true;
    if (prefixMatched(number, 5)) return true;
    if (prefixMatched(number, 37)) return true;
    if (prefixMatched(number, 6)) return true;
    return false;
}

/* Sum of even numbers */
int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;
    while (number > 0) {
        int digit = (int) ((number % 100) / 10);
        number /= 100;
        sum += getDigit(2 * digit);
    };
    return sum;
}

// Return this number if it is a single digit; otherwise, return the sum
// of the two digits
int getDigit(int number) {
    return (number / 10) + (number % 10); // Still works the same if it's a single digit number.
}

// Return sum of odd-place digits in number.
int sumOfOddPlace(long long number) {
    int sum = 0;
    while (number > 0) {
        int digit = (int) (number % 10);
        number /= 100;
        sum += getDigit(digit);
    };
    return sum;
}

// Return true if the digit is a prefix for this number.
bool prefixMatched(long long number, int digit) {
    return getPrefix(number, getSize(digit)) == digit;
}

// Return the number of digits in number
int getSize(long long number) {
    int digitCount = 0;
    while (number > 0) {
        number /= 10; // Chop off one digit.
        digitCount++;
    }
    return digitCount;
}

// Return the first numDigits digits from number. If the no. of digits
// in number is less than numDigits, return number
int getPrefix(long long number, int numDigits) {
    int numberSize = getSize(number);
    int decimalMovements = numberSize - numDigits;
    while (decimalMovements-- > 0) {
        number /= 10;
    };
    return number;
}

/* User requested for input */
int main() {
    cout << "Enter a credit card number: " << endl;
    long long magicNumber = getNumber();

    /* Response to enterd number */
    if (isValid(magicNumber)) {
        cout << magicNumber << " is valid." << endl;
    } else {
        cout << magicNumber << " is invalid." << endl;
    }
      return 0;
}
