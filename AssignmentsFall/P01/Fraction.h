// Fraction.h

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>
#include <string>

class Fraction {
private:
    int num; // Numerator
    int den; // Denominator

    int gcd(int a, int b) const; // Function to compute the greatest common divisor (GCD)
    void reduce(); // Function to reduce the fraction to its simplest form
    int lcd(int a, int b) const; // Function to find the least common denominator (LCD)

public:
    Fraction(); // Default constructor
    Fraction(int n, int d); // Constructor with parameters
    Fraction(std::string f); // Constructor that takes a string like "3/4"

    int setFraction(int n, int d); // Setter for initializing the fraction
    int getNumerator() const; // Getter for numerator
    int getDenominator() const; // Getter for denominator
    void setNumerator(int n); // Setter for numerator
    void setDenominator(int d); // Setter for denominator
    void print() const; // Print fraction in the form numerator/denominator

    // Overloaded operators
    friend std::ostream& operator<<(std::ostream& os, const Fraction& rhs);
    Fraction operator+(const Fraction& rhs) const;
    Fraction operator-(const Fraction& rhs) const;
    Fraction operator*(const Fraction& rhs) const;
    Fraction operator/(const Fraction& rhs) const;
    bool operator==(const Fraction& rhs) const;
};

#endif

