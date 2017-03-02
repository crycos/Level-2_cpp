#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float a;
    float b;
    float c;
    /* Request user input for values a, b, c */
    cout << "Enter a, b, c: " << endl;
    cin >> a >> b >> c;

    float r1;
    float r2;
    float discriminant;
    discriminant = (b * b) - (4 * a * c);
    r1 = (-b + sqrt(discriminant)) / (2 * a);
    r2 = (-b - sqrt(discriminant)) / (2 * a);

    /* Display results based on discriminant */
    if (discriminant < 0) {
        cout << "The equation has no real roots." << endl;
    }
    else if (discriminant > 0) {
        cout << "The equation has two roots: " << r1 << " and " << r2 << endl;
    }
    else {
        r1 = r2;
        cout << "The equation has one root: " << r1;
    }
    // Test. Case 1, one solution: 2,4,2. Case 2, two solutions 5, -15, 0 . Case 3, no solution 5,5,3.
    return 0;
}
