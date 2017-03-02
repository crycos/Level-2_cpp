#include <iostream>
using namespace std;


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

int sumOfDoubleEvenPlace(long long number) {
    int
    int sum = 0;
    while (number > 0) {
        int digit = (int) ((number % 100) / 10);
        number /= 100;
        sum += getDigit(2 * digit);
    };
    return sum;
}

int getDigit(int number) {
    return (number / 10) + (number % 10); // Still works the same if it's a single digit number.
}

int sumOfOddPlace(long long number) {
    int sum = 0;
    while (number > 0) {
        int digit = (int) (number % 10);
        number /= 100;
        sum += getDigit(digit);
    };
    return sum;
}

bool prefixMatched(long long number, int digit) {
    return getPrefix(number, getSize(digit)) == digit;
}

int getSize(long long number) {
    int digitCount = 0;
    while (number > 0) {
        number /= 10; // Chop off one digit.
        digitCount++;
    }
    return digitCount;
}

long getPrefix(long long number, int numDigits) {
    int numberSize = getSize(number);
    int decimalMovements = numberSize - numDigits;
    while (decimalMovements-- > 0) {
        number /= 10;
    };
    return number;
}
int main() {
    cout << "Enter a credit card number: " << endl;
    const auto number;
    cin >> number;
    if (isValid(number))
        cout << number << " is valid." << endl;
    else
        cout << number << " is invalid." << endl;
    return 0;
}
