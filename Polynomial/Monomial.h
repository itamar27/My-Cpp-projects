#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Monomial
{

private:
    int m_coeff;
    int m_exp;

public:
    Monomial();
    Monomial(int coeff, int exp = 0);

    int getCoeff() const;
    int getExp() const;

    //-----Opreator overloading-----//
    const Monomial &operator+=(const Monomial &x);
    Monomial operator*(const Monomial &x);
    const Monomial &operator*=(const Monomial &x);
    bool operator==(const Monomial &x) const;
    void negate();

    friend ostream &operator<<(ostream &out, const Monomial &m);

    char *stringRepresentation() const;
};

std::ostream &operator<<(std::ostream &out, const Monomial &m);

char *intToString(int n); // Helping side function that get int and return an string of it