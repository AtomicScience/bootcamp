#include <iostream>
#include <math.h>

using namespace std;

int readCoefficient(string prompt) {
    cout << prompt << endl;

    int coefficient;
    cin >> coefficient;
    return coefficient;
}

int main() {
    cout << "Enter the coefficients of the equation" << endl;

    int a = readCoefficient("A (square):");
    int b = readCoefficient("B (linear):");
    int c = readCoefficient("C (free):");

    double discriminant = b * b - 4 * a * c;

    if(discriminant < 0) {
        cout << "No roots" << endl;
        return 0;
    } else {
        double firstRoot = (-b + sqrt(discriminant)) / 2 * a;
        double secondRoot = (-b - sqrt(discriminant)) / 2 * a;

        if(discriminant == 0) {
            cout << "Root: " << firstRoot << endl;
        } else {
            cout << "Roots: " << firstRoot << ", " << secondRoot << endl;
        }
    }

    return 0;
}