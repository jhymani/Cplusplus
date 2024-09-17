// main.cpp

#include <iostream>
#include "Fraction.h"

using namespace std;

int main() {
    string f1, op, f2;

    while (cin >> f1 >> op >> f2) {
        Fraction F1(f1);
        Fraction F2(f2);

        if (op == "+") {
            cout << F1 << " + " << F2 << " = " << F1 + F2 << endl;
        } else if (op == "-") {
            cout << F1 << " - " << F2 << " = " << F1 - F2 << endl;
        } else if (op == "*") {
            cout << F1 << " * " << F2 << " = " << F1 * F2 << endl;
        } else if (op == "/") {
            cout << F1 << " / " << F2 << " = " << F1 / F2 << endl;
        } else if (op == "==") {
            cout << F1 << " == " << F2 << " = " << (F1 == F2 ? "True" : "False") << endl;
        } else {
            cout << "Invalid operator" << endl;
        }
    }

    return 0;
}
