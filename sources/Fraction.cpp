
#include "Fraction.hpp"
#include <string>
#include <sstream>
#include <limits>

using namespace std;
using namespace ariel;

/// @brief The function returns the reduced form of the fraction
/// @param frac 
/// @return The reduced form of the fraction
Fraction minFrac(Fraction frac){
    int divMin = gcd(frac.getNumerator(), frac.getDenominator());
    return Fraction(frac.getNumerator()/divMin, frac.getDenominator()/divMin);
}

Fraction operator+ (const Fraction& a, const Fraction& other){
    Fraction newC1 = minFrac(a);
    Fraction newC2 = minFrac(other);

    int newA_num = newC1.numerator * newC2.denominator;  
    int newB_num = newC2.numerator * newC1.denominator; 
    if (((long long)newA_num + newB_num > std::numeric_limits<int>::max())
    || ((long long)newA_num + newB_num < std::numeric_limits<int>::min())) 
    {
        throw std::overflow_error("Error: Can't multiply too big fractions");
    }
    int num = newA_num + newB_num;
    int den = newC1.denominator * newC2.denominator;;
    int divMin = gcd(num, den);
    return Fraction(num/divMin, den/divMin);
}
Fraction operator+ (const Fraction& a, const float& other){
    Fraction b = Fraction(other);
    return b+a;
}
Fraction operator+ (const float& a, const Fraction& other){
    Fraction b = Fraction(a);
    return b+other;
}

Fraction operator- (const Fraction& a, const Fraction& other){
    int newA_num = a.numerator * other.denominator;  
    int newB_num = other.numerator * a.denominator; 
    int num = newA_num - newB_num;
    if (((long long)newA_num - newB_num > std::numeric_limits<int>::max())
    || ((long long)newA_num - newB_num < std::numeric_limits<int>::min())) 
    {
        throw std::overflow_error("Error: Can't multiply too big fractions");
    }
    int den = a.denominator * other.denominator;;
    int divMin = gcd(num, den);
    return Fraction(num/divMin, den/divMin);
}
Fraction operator- (const Fraction& a, const float& other){
    Fraction b = Fraction(other);
    return a-b;
}
Fraction operator- (const float& a, const Fraction& other){
    Fraction b = Fraction(a);
    return b-other;
}

Fraction operator* (const Fraction& c1, const Fraction& c2){
    Fraction newC1 = minFrac(c1);
    Fraction newC2 = minFrac(c2);
    if (((long long)newC1.numerator * newC2.numerator > std::numeric_limits<int>::max())
    || ((long long)newC1.denominator * newC2.denominator > std::numeric_limits<int>::max())) {
        throw std::overflow_error("Error: Can't multiply too big fractions");
    }
    int new_num = newC1.numerator * newC2.numerator;  
    int new_den = newC1.denominator * newC2.denominator;  
    int divMin = gcd(new_num, new_den);
    return Fraction(new_num/divMin, new_den/divMin);
}
Fraction operator* (const Fraction& a, const float& other){
    Fraction b = Fraction(other);
    return a*b;
}
Fraction operator* (const float& a, const Fraction& other){
    Fraction b = Fraction(a);
    return b*other;
}

Fraction operator/ (const Fraction& c1, const Fraction& c2){
    if (c2.numerator == 0){
        throw std::runtime_error("Error: division by zero");
    }
    Fraction inverseFrac(c2.denominator, c2.numerator);
    return c1*inverseFrac;
}
Fraction operator/ (const Fraction& a, const float& other){
    Fraction b = Fraction(other);
    if (b.denominator == 0 || b.numerator ==0){
        throw std::runtime_error("Error: division by zero");
    }
    return a/b;
}
Fraction operator/ (const float& a, const Fraction& other){
    Fraction b = Fraction(a);
    if (other.numerator == 0){
        throw std::runtime_error("Error: division by zero");
    }
    return b/other;
}

bool operator==(const Fraction& c1, const Fraction& c2){
    Fraction minC1 = minFrac(c1);
    Fraction minC2 = minFrac(c2);
    bool first = (minC1.numerator == minC2.numerator) && (minC1.denominator == minC2.denominator);
    bool second = (c1.numerator == 0 && c2.numerator ==0);
    return (first || second);
}
bool operator== (const float& c1, const Fraction& c2){
    Fraction b = Fraction(c1);
    return b==c2;
}
bool operator== (const Fraction& c1, const float& c2){
    Fraction b = Fraction(c2);
    return c1==b;
}

bool operator!=(const Fraction& c1, const Fraction& c2){
    Fraction minC1 = minFrac(c1);
    Fraction minC2 = minFrac(c2);
    bool first = (minC1.numerator != minC2.numerator) || (minC1.denominator != minC2.denominator);
    bool second = (c1.numerator != 0 || c2.numerator !=0);
    return (first && second);
}
bool operator!= (const float& c1, const Fraction& c2){
    Fraction b = Fraction(c1);
    return b!=c2;
}
bool operator!= (const Fraction& c1, const float& c2){
    Fraction b = Fraction(c2);
    return c1!=b;
}

bool operator> (const Fraction& c1, const Fraction& c2){
    int newA_num = c1.numerator * c2.denominator;  
    int newB_num = c2.numerator * c1.denominator; 
    if(newA_num > newB_num) return 1; 
    else return 0; 
}
bool operator> (const float& c1, const Fraction& c2){
    Fraction b = Fraction(c1);
    return b>c2;
}
bool operator> (const Fraction& c1, const float& c2){
    Fraction b = Fraction(c2);
    return c1>b;
}

bool operator< (const Fraction& c1, const Fraction& c2){
    int newA_num = c1.numerator * c2.denominator;  
    int newB_num = c2.numerator * c1.denominator; 
    if(newA_num < newB_num) return 1; 
    else return 0; 
}
bool operator< (const float& c1, const Fraction& c2){
    Fraction b = Fraction(c1);
    return b<c2;
}
bool operator< (const Fraction& c1, const float& c2){
    Fraction b = Fraction(c2);
    return c1<b;
}

bool operator>= (const Fraction& c1, const Fraction& c2){
    int newA_num = c1.numerator * c2.denominator;  
    int newB_num = c2.numerator * c1.denominator; 
    if(newA_num >= newB_num) return 1; 
    else return 0; 
}
bool operator>= (const float& c1, const Fraction& c2){
    Fraction b = Fraction(c1);
    return b>=c2;
}
bool operator>= (const Fraction& c1, const float& c2){
    Fraction b = Fraction(c2);
    return c1>=b;
}

bool operator<= (const Fraction& c1, const Fraction& c2){
    int newA_num = c1.numerator * c2.denominator;  
    int newB_num = c2.numerator * c1.denominator; 
    if(newA_num <= newB_num) return 1; 
    else return 0; 
}
bool operator<= (const float& c1, const Fraction& c2){
    Fraction b = Fraction(c1);
    return b<=c2;
}
bool operator<= (const Fraction& c1, const float& c2){
    Fraction b = Fraction(c2);
    return c1<=b;
}

//----------------------------------
// friend global IO operators
//----------------------------------
std::ostream& operator<< (std::ostream& output, const Fraction& c){
    Fraction newfrac = minFrac(c);
    return (output << newfrac.getNumerator() << '/' << newfrac.getDenominator());
}

istream& operator>> (istream& input, Fraction& c) {
    //I used to this function chatgpt

    int num, den;
    if (input >> num >> den) {
        if (den == 0) {
            throw std::runtime_error("Error: denominator cannot be zero");
            input.setstate(std::ios::failbit);
        } else if (den < 0) {
            num = -num;
            den = -den;
        }
        c = Fraction(num, den);
    }
    else{
        throw std::runtime_error("Error: input format should be 'numerator denominator'.");
        input.setstate(std::ios::failbit);
    }
    return input;

}