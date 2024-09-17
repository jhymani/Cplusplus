// Jhymani Joseph
// Assignment 1
// This program demonstrates addition, multiplacation and
// substraction of fractions.
// GCD Calculation: Used to simplify fractions.
// LCD Calculation: Used to find the least common denominator for addition and subtraction.
// Addition and Subtraction: Adjusted fractions to a common denominator before performing operations.
// Multiplication: Multiplied numerators and denominators directly.
// Reduction: Simplified fractions after operations.
// Setters and Getters: Added methods to modify and access the private members of the class.

// Fraction.cpp

#include "Fraction.h"

// Default constructor initializes the fraction to 0/1.
Fraction::Fraction() : num(0), den(1) {}

// Constructor that initializes the fraction with given numerator and denominator.
Fraction::Fraction(int n, int d) : num(n), den(d) {
    if (d == 0) {
        std::cerr << "Error: Denominator cannot be zero." << std::endl;
        num = 0;
        den = 1; // Default to a valid fraction
    } else {
        reduce(); // Simplify the fraction
    }
}

// Constructor that initializes the fraction from a string in the format "n/d".
Fraction::Fraction(std::string f) {
    size_t slashPos = f.find('/');
    if (slashPos == std::string::npos) {
        std::cerr << "Error: Invalid fraction format." << std::endl;
        num = 0;
        den = 1; // Default to a valid fraction
    } else {
        try {
            num = std::stoi(f.substr(0, slashPos)); // Extract numerator
            den = std::stoi(f.substr(slashPos + 1)); // Extract denominator
            if (den == 0) {
                throw std::invalid_argument("Denominator cannot be zero.");
            }
            reduce(); // Simplify the fraction
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            num = 0;
            den = 1; // Default to a valid fraction
        }
    }
}

// Computes the greatest common divisor (GCD) of two integers using the Euclidean algorithm.
int Fraction::gcd(int a, int b) const {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Reduces the fraction to its simplest form.
void Fraction::reduce() {
    int divisor = gcd(std::abs(num), std::abs(den)); // Find GCD
    num /= divisor; // Divide numerator by GCD
    den /= divisor; // Divide denominator by GCD

    // Ensure the denominator is positive
    if (den < 0) {
        den = -den;
        num = -num;
    }
}

// Finds the least common denominator (LCD) of two integers.
int Fraction::lcd(int a, int b) const {
    return a * (b / gcd(a, b));
}

// Sets the fraction to a new numerator and denominator.
int Fraction::setFraction(int n, int d) {
    if (d == 0) {
        std::cerr << "Error: Denominator cannot be zero." << std::endl;
        return -1; // Error code for invalid denominator
    }
    num = n;
    den = d;
    reduce(); // Simplify the fraction
    return 0;
}

// Returns the numerator of the fraction.
int Fraction::getNumerator() const { 
    return num; 
}

// Returns the denominator of the fraction.
int Fraction::getDenominator() const { 
    return den; 
}

// Sets the numerator to a new value and reduces the fraction.
void Fraction::setNumerator(int n) { 
    num = n; 
    reduce(); 
}

// Sets the denominator to a new value, ensuring it's not zero, and reduces the fraction.
void Fraction::setDenominator(int d) {
    if (d == 0) {
        std::cerr << "Error: Denominator cannot be zero." << std::endl;
        return;
    }
    den = d;
    reduce(); // Simplify the fraction
}

// Prints the fraction in the format "numerator/denominator".
void Fraction::print() const {
    std::cout << num << "/" << den << std::endl;
}

// Overloads the output stream operator to print the fraction.
std::ostream& operator<<(std::ostream& os, const Fraction& rhs) {
    os << rhs.num << "/" << rhs.den;
    return os;
}

// Overloads the addition operator to add two fractions.
Fraction Fraction::operator+(const Fraction& rhs) const {
    int commonDenominator = lcd(this->den, rhs.den); // Find least common denominator
    int newNum = (this->num * (commonDenominator / this->den)) + 
                 (rhs.num * (commonDenominator / rhs.den)); // Adjust numerators and add
    return Fraction(newNum, commonDenominator); // Return the resulting fraction
}

// Overloads the subtraction operator to subtract two fractions.
Fraction Fraction::operator-(const Fraction& rhs) const {
    int commonDenominator = lcd(this->den, rhs.den); // Find least common denominator
    int newNum = (this->num * (commonDenominator / this->den)) - 
                 (rhs.num * (commonDenominator / rhs.den)); // Adjust numerators and subtract
    return Fraction(newNum, commonDenominator); // Return the resulting fraction
}

// Overloads the multiplication operator to multiply two fractions.
Fraction Fraction::operator*(const Fraction& rhs) const {
    int newNum = this->num * rhs.num; // Multiply numerators
    int newDen = this->den * rhs.den; // Multiply denominators
    return Fraction(newNum, newDen); // Return the resulting fraction
}

// Overloads the division operator to divide two fractions.
Fraction Fraction::operator/(const Fraction& rhs) const {
    if (rhs.num == 0) {
        std::cerr << "Error: Division by zero." << std::endl;
        return Fraction(); // Return a default fraction
    }
    int newNum = this->num * rhs.den; // Multiply numerator by denominator of the second fraction
    int newDen = this->den * rhs.num; // Multiply denominator by numerator of the second fraction
    return Fraction(newNum, newDen); // Return the resulting fraction
}

// Overloads the equality operator to compare two fractions.
bool Fraction::operator==(const Fraction& rhs) const {
    return (this->num == rhs.num) && (this->den == rhs.den);
}
