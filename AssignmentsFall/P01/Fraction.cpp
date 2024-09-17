// Jhymani Joseph
// Assignment 1
// This program demonstrates addition, multiplacation and
// substraction of fractions.
// Addition and Subtraction: Adjusted fractions to a common denominator before performing operations.
// Multiplication: Multiplied numerators and denominators directly.
// Setters and Getters: Added methods to modify and access the private members of the class.
// Constructor and Error Handling: Detailed comments on constructors, especially the one taking a string and 
// ensuring the denominator is not zero.
// GCD and LCD Calculation: Clear explanations on how the gcd and lcd functions work, including their purpose 
// in reducing and finding common denominators for fractions.
// Operator Overloading: Explained how each operator overload (+, -, *, /, ==) is implemented, 
// focusing on the logic behind using the least common denominator (LCD) for addition and subtraction.
// Fraction Reduction: Comments added to the reduce method to explain why it's necessary to always keep
// the denominator positive and simplify the fraction.

// Fraction.cpp

#include "Fraction.h"

// Default constructor initializes the fraction to 0/1.
Fraction::Fraction() : num(0), den(1) {}

// Constructor that initializes the fraction with given numerator and denominator.
// If the denominator is zero, it sets the fraction to 0/1 and prints an error message.
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
// It extracts the numerator and denominator from the string and converts them to integers.
Fraction::Fraction(std::string f) {
    num = f[0] - '0'; // Convert char to int for numerator
    den = f[2] - '0'; // Convert char to int for denominator
    reduce(); // Simplify the fraction
}

// Computes the greatest common divisor (GCD) of two integers using the Euclidean algorithm.
// This function is used to reduce fractions to their simplest form.
int Fraction::gcd(int a, int b) const {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Reduces the fraction to its simplest form by dividing both the numerator and denominator
// by their greatest common divisor (GCD). Ensures the denominator is always positive.
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
// It uses the relationship LCD(a, b) = (a * b) / GCD(a, b).
// This is used to add or subtract fractions.
int Fraction::lcd(int a, int b) const {
    return a * (b / gcd(a, b));
}

// Sets the fraction to a new numerator and denominator, and reduces it.
// If the denominator is zero, it returns an error code.
int Fraction::setFraction(int n, int d) {
    if (d == 0) {
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
// If the denominator is zero, it prints an error message.
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

// Overloads the output stream operator to print the fraction in the format "numerator/denominator".
std::ostream& operator<<(std::ostream& os, const Fraction& rhs) {
    os << rhs.num << "/" << rhs.den;
    return os;
}

// Overloads the addition operator to add two fractions.
// It finds a common denominator using LCD, adjusts the numerators accordingly, and returns a new Fraction.

Fraction Fraction::operator+(const Fraction& rhs) const {
    int commonDenominator = lcd(this->den, rhs.den); // Find least common denominator
    int newNum = (this->num * (commonDenominator / this->den)) + 
                 (rhs.num * (commonDenominator / rhs.den)); // Adjust numerators and add
    return Fraction(newNum, commonDenominator); // Return the resulting fraction
}

// Overloads the subtraction operator to subtract two fractions.

// It finds a common denominator using LCD, adjusts the numerators accordingly, and returns a new Fraction.

Fraction Fraction::operator-(const Fraction& rhs) const {
    int commonDenominator = lcd(this->den, rhs.den); // Find least common denominator
    
    int newNum = (this->num * (commonDenominator / this->den)) - 
                 (rhs.num * (commonDenominator / rhs.den)); // Adjust numerators and subtract
    
    return Fraction(newNum, commonDenominator); // Return the resulting fraction
}

// Overloads the multiplication operator to multiply two fractions.
// It multiplies the numerators and denominators directly and returns a new Fraction.

Fraction Fraction::operator*(const Fraction& rhs) const {
    int newNum = this->num * rhs.num; // Multiply numerators
    int newDen = this->den * rhs.den; // Multiply denominators
    return Fraction(newNum, newDen); // Return the resulting fraction
}

// Overloads the division operator to divide two fractions.
// It multiplies the first fraction by the reciprocal of the second.

Fraction Fraction::operator/(const Fraction& rhs) const {
    int newNum = this->num * rhs.den; // Multiply numerator by denominator of the second fraction
    int newDen = this->den * rhs.num; // Multiply denominator by numerator of the second fraction
    return Fraction(newNum, newDen); // Return the resulting fraction
}

// Overloads the equality operator to compare two fractions.
// It returns true if both the numerator and denominator are equal.

bool Fraction::operator==(const Fraction& rhs) const {
    return (this->num == rhs.num) && (this->den == rhs.den);
}
