// main.cpp

#include <iostream>
#include "Fraction.h"

using namespace std;

int main() {
    string f1, op, f2;
    int iteration = 0; // Counter for the number of iterations

    cout << "Enter fractions and operator in the form of a/b operator c/d" << endl;

    while (iteration < 4 && cin >> f1 >> op >> f2) {
        Fraction F1(f1);
        Fraction F2(f2);

        if (op == "+") {
            cout << F1 << " + " << F2 << " = " << F1 + F2 << endl;
        } else if (op == "-") {
            cout << F1 << " - " << F2 << " = " << F1 - F2 << endl;
        } else if (op == "*") {
            cout << F1 << " * " << F2 << " = " << F1 * F2 << endl;
        } else if (op == "/") {
            if (F2.getNumerator() == 0) {
                cout << "Error: Division by zero." << endl;
            } else {
                cout << F1 << " / " << F2 << " = " << F1 / F2 << endl;
            }
        } else if (op == "==") {
            cout << F1 << " == " << F2 << " = " << (F1 == F2 ? "True" : "False") << endl;
        } else {
            cout << "Invalid operator" << endl;
        }

        iteration++; // Increment the iteration counter

        if (iteration < 4) {
            cout << "Enter 2 fractions and operator in the middle:" << endl;
        }
    }

    cout << "Program has completed after 4 iterations." << endl;

    return 0;
}
