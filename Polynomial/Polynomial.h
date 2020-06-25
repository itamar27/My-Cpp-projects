#pragma once

#include <iostream>
#include "Monomial.h"

class Polynomial
{
private:
    Monomial *m_pol;
    int m_count;

public:
    Polynomial();
    Polynomial(const Polynomial &p);
    Polynomial(const Monomial &m);
    ~Polynomial();

public:
    const Polynomial &operator=(const Polynomial &p);
    const Polynomial &operator+=(const Polynomial &p);
    const Polynomial &operator+=(const Monomial &m);
    const Polynomial &operator-=(const Polynomial &p);
    const Polynomial &operator-=(const Monomial &m);
    const Polynomial &operator*=(const Polynomial &p);
    const Polynomial &operator*=(const Monomial &m);
    int operator[](const int exp) const;

    Polynomial operator+(const Polynomial &p) const;
    friend Polynomial operator+(const Polynomial &p, const Monomial &m);
    friend Polynomial operator+(const Monomial &m, const Polynomial &p);

    Polynomial operator-(const Polynomial &p) const;
    friend Polynomial operator-(const Polynomial &p, const Monomial &m);
    friend Polynomial operator-(const Monomial &m, const Polynomial &p);

    Polynomial operator*(const Polynomial &p) const;
    friend Polynomial operator*(const Polynomial &p, const Monomial &m);
    friend Polynomial operator*(const Monomial &m, const Polynomial &p);

public:
    void sort();
    int maxExp() const;
    const char *getStringRepresentation() const;

    friend std::ostream &operator<<(std::ostream &out, const Polynomial &p);
    Polynomial &operator>>(const char *str);
};

std::ostream &operator<<(std::ostream &out, const Polynomial &p);
Polynomial operator+(const Polynomial &p, const Monomial &m);
Polynomial operator+(const Monomial &m, const Polynomial &p);
Polynomial operator-(const Polynomial &p, const Monomial &m);
Polynomial operator-(const Monomial &m, const Polynomial &p);
Polynomial operator-(const Polynomial &p, const Monomial &m);
Polynomial operator-(const Monomial &m, const Polynomial &p);
