// #pragma once
#include <iostream>
#include <stdexcept>
#include <numeric>
#include <cmath>


#ifndef FRACTION_H
#define FRACTION_H

namespace ariel {};
    class Fraction{
      
        private:
            static const int ROUNDDOT = 1000;
            static const int MAXDIGIT = 10;
            int numerator;
            int denominator; 
                            
        public:

            Fraction(double num){
                std::string num_str = std::to_string(num);
                if(num_str.length() > MAXDIGIT){
                    throw std::runtime_error("Error: the number should be float type, you entred too longer number");
                }
                int rounded_number = static_cast<int>(std::round(num * ROUNDDOT));
                int gcd = std::gcd(rounded_number, ROUNDDOT);
                this->numerator = rounded_number/gcd;
                this->denominator = ROUNDDOT/gcd;
            }

             // Constructor. Also works as a conversion from double and
            // also as a default ctor.
            Fraction (const int number = 0, int denum = 1): numerator(number), denominator(denum) {
                if(denum == 0){
                    throw std::invalid_argument("Error: 0 at the denominator");
                }
                if(denum<0){
                    this->numerator = (-1) * number;
                    this->denominator = (-1) * denum;
                }
                else{
                    this->denominator = denum;
                    this->numerator = number;
                }
            }

            //-------------------------------------
            // getters
            //-------------------------------------
            int getNumerator() const {
                return numerator;
            }

            int getDenominator() const {
                return denominator;
            }

            Fraction operator-() const {
                return Fraction(-numerator , denominator);
            }

            friend Fraction operator+ (const Fraction& a11, const Fraction& other);
            friend Fraction operator+ (const Fraction& a11, const float& other);
            friend Fraction operator+ (const float& a11, const Fraction& other);

            friend Fraction operator- (const Fraction& c11, const Fraction& c22);
            friend Fraction operator- (const Fraction& a11, const float& other);
            friend Fraction operator- (const float& a11, const Fraction& other);

            friend Fraction operator* (const Fraction& c11, const Fraction& c22);
            friend Fraction operator* (const Fraction& a11, const float& other);
            friend Fraction operator* (const float& a11, const Fraction& other);

            friend Fraction operator/ (const Fraction& c11, const Fraction& c22);
            friend Fraction operator/ (const Fraction& a11, const float& other);
            friend Fraction operator/ (const float& a11, const Fraction& other);

           
            friend bool operator>= (const Fraction& c11, const Fraction& c22);
            friend bool operator>= (const float& c11, const Fraction& c22);
            friend bool operator>= (const Fraction& c11, const float& c22);

            friend bool operator<= (const Fraction& c11, const Fraction& c22);
            friend bool operator<= (const float& c11, const Fraction& c22);
            friend bool operator<= (const Fraction& c11, const float& c22);

            friend bool operator> (const Fraction& c11, const Fraction& c22);
            friend bool operator> (const float& c11, const Fraction& c22);
            friend bool operator> (const Fraction& c11, const float& c22);

            friend bool operator< (const Fraction& c11, const Fraction& c22);
            friend bool operator< (const float& c11, const Fraction& c22);
            friend bool operator< (const Fraction& c11, const float& c22);


            friend bool operator==(const Fraction& c11, const Fraction& c22);
            friend bool operator== (const float& c11, const Fraction& c22);
            friend bool operator== (const Fraction& c11, const float& c22);

            friend bool operator!=(const Fraction& c11, const Fraction& c22);
            friend bool operator!= (const float& c11, const Fraction& c22);
            friend bool operator!= (const Fraction& c11, const float& c22);


            // prefix increment:
            Fraction& operator++() {
                this->numerator = this->numerator + this->denominator;
                return *this;
            }

            // postfix increment:
            Fraction operator++(int dummy_flag_for_postfix_increment) {
                Fraction copy = *this;
                this->numerator = this->numerator + this->denominator;
                return copy;
            }
            
            // prefix reduction:
            Fraction& operator--() {
                this->numerator = this->numerator - this->denominator;
                return *this;
            }

            // postfix reduction:
            Fraction operator--(int dummy_flag_for_postfix_increment) {
                Fraction copy = *this;
                this->numerator = this->numerator - this->denominator;
                return copy;
            }
        
            //----------------------------------
            // friend global IO operators
            //----------------------------------
            friend std::ostream& operator<< (std::ostream& output, const Fraction& c11);
            friend std::istream& operator>> (std::istream& input , Fraction& c11);

            //-------------------------------------
    };
#endif