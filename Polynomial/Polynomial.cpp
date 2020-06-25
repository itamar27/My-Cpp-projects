#include "Polynomial.h"

Polynomial ::Polynomial()
{
    m_pol = nullptr;
    m_count = 0;
}

//----------------------------------------------------------------------//

Polynomial ::Polynomial(const Polynomial &p)
{
    m_pol = nullptr;
    *this = p;
}

//---------------------------------------------------------------------//

Polynomial ::Polynomial(const Monomial &m)
{
    if (m.getCoeff() == 0)
    {
        m_pol = nullptr;
        m_count = 0;
    }

    else
    {
        m_pol = new Monomial[1];
        *m_pol = m;
        m_count = 1;
    }
}

//----------------------------------------------------------------------//

const Polynomial &Polynomial ::operator=(const Polynomial &p)
{
    if (this != &p)
    {
        m_count = p.m_count;
        delete[] m_pol;
        m_pol = new Monomial[m_count];
        for (int i = 0; i < m_count; ++i)
            m_pol[i] = p.m_pol[i];
    }
    return *this;
}

//----------------------------------------------------------------------//

const Polynomial &Polynomial::operator+=(const Polynomial &p)
{
    for (int i = 0; i < p.m_count; ++i)
    {
        *this += p.m_pol[i];
    }
    return *this;
}

//----------------------------------------------------------------------//

const Polynomial &Polynomial::operator+=(const Monomial &m)
{
    int i = 0;
    for (; i < m_count; ++i) //Checking for a matching exponent.
    {
        try
        {
            m_pol[i] += m;
            break;
        }
        catch (...)
        {
            continue;
        }
    }

    if (i == m_count) //If theres no matching exponent, makes a new Monom
    {
        m_count++;
        Monomial *tmp = new Monomial[m_count];
        for (int j = 0; j < m_count - 1; ++j)
        {
            tmp[j] = m_pol[j];
        }
        tmp[m_count - 1] = m;
        delete[] m_pol;
        m_pol = tmp;
    }
    this->sort();
    return *this;
}

//----------------------------------------------------------------------//

const Polynomial &Polynomial::operator-=(const Polynomial &p)
{
    for (int i = 0; i < p.m_count; ++i)
    {
        Monomial tmp = p.m_pol[i];
        tmp.negate();
        *this += tmp;
    }

    return *this;
}

//----------------------------------------------------------------------//

const Polynomial &Polynomial ::operator-=(const Monomial &m)
{
    Monomial tmp = m;
    tmp.negate();
    *this += tmp;

    return *this;
}

//----------------------------------------------------------------------//

const Polynomial &Polynomial ::operator*=(const Polynomial &p)
{
    Polynomial tmpPoly;
    Polynomial tmpPoly2;
    for (int i = 0; i < p.m_count; ++i)
    {
        tmpPoly = *this;
        tmpPoly *= p.m_pol[i];
        tmpPoly2 += tmpPoly;
    }

    delete[] m_pol;
    *this = tmpPoly2;
    return *this;
}

//----------------------------------------------------------------------//

const Polynomial &Polynomial ::operator*=(const Monomial &m)
{
    Polynomial tmpPoly;
    for (int i = 0; i < m_count; ++i)
    {
        tmpPoly += (m_pol[i] * m);
    }
    delete[] m_pol;
    *this = tmpPoly;
    return *this;
}

//----------------------------------------------------------------------//

int Polynomial ::operator[](const int exp) const
{

    for (int i = 0; i < m_count; ++i)
    {
        if (m_pol[i].getExp() == exp)
            return m_pol[i].getCoeff();
    }
    return 0;
}

//----------------------------------------------------------------------//

Polynomial Polynomial ::operator+(const Polynomial &p) const
{
    Polynomial tmp = *this;
    tmp += p;
    return tmp;
}

//----------------------------------------------------------------------//

Polynomial operator+(const Polynomial &p, const Monomial &m)
{
    Polynomial tmp = p;
    tmp += m;
    return tmp;
}

//----------------------------------------------------------------------//

Polynomial operator+(const Monomial &m, const Polynomial &p)
{
    return p + m;
}

//----------------------------------------------------------------------//

Polynomial Polynomial ::operator-(const Polynomial &p) const
{
    Polynomial tmp = *this;
    tmp -= p;
    return tmp;
}

//----------------------------------------------------------------------//

Polynomial operator-(const Polynomial &p, const Monomial &m)
{
    Polynomial tmp = p;
    tmp -= m;
    return tmp;
}

//----------------------------------------------------------------------//

Polynomial operator-(const Monomial &m, const Polynomial &p)
{
    Monomial minus(-1, 0);
    return (p * minus) + m;
}

//----------------------------------------------------------------------//

Polynomial Polynomial ::operator*(const Polynomial &p) const
{
    Polynomial tmp = *this;
    tmp *= p;
    return tmp;
}

//----------------------------------------------------------------------//

Polynomial operator*(const Polynomial &p, const Monomial &m)
{
    Polynomial tmp = p;
    tmp *= m;
    return tmp;
}

//----------------------------------------------------------------------//

Polynomial operator*(const Monomial &m, const Polynomial &p)
{
    return p * m;
}

//----------------------------------------------------------------------//

const char *Polynomial::getStringRepresentation() const
{
    if (m_count == 0)
    {
        char *c = new char[2]; //Private case when the polynom equals 0.
        *c = '0';
        *(c + 1) = '\0';
        return c;
    }

    char *tmp = nullptr;
    char *str = nullptr;
    int size = 0;
    bool val = false; //A flag to point if the monom is positive or negative.
    for (int i = 0; i < m_count; ++i)
    {
        tmp = m_pol[i].stringRepresentation();
        if (m_pol[i].getCoeff() >= 0 && i != 0)
        {
            val = true;
            ++size;
        }
        str = (char *)realloc(str, size + strlen(tmp));
        if (val)
        {
            str[size - 1] = '+';
            val = false;
        }
        strncpy(str + size, tmp, strlen(tmp));
        size += strlen(tmp);
    }
    str = (char *)realloc(str, size + 1);
    *(str + size) = '\0';
    return str;
}

//----------------------------------------------------------------------//

std::ostream &operator<<(std::ostream &out, const Polynomial &p)
{
    out << p.getStringRepresentation();
    return out;
}

//----------------------------------------------------------------------//

void Polynomial ::sort()
{
    if (m_pol == nullptr)
        throw "Empty array of monomials";

    int index = m_count - 1;
    int i = 0;

    for (; i <= index;) // A loop to sort 0 in the end of the Monomial array
    {
        if (m_pol[index].getCoeff() == 0)
            --index;
        else if (m_pol[i].getCoeff() == 0)
        {
            Monomial tmp = m_pol[index];
            m_pol[index] = m_pol[i];
            m_pol[i] = tmp;
            index--;
            ++i;
        }
        else
            ++i;
    }

    if (0 != index)
        m_count = index + 1;

    Monomial *tmp = new Monomial[m_count];
    for (int j = 0; j < m_count; ++j)
    {
        tmp[j] = m_pol[j];
    }
    delete[] m_pol;
    m_pol = tmp;

    for (i = 0; i < m_count; ++i) // A Loop to sort all the polynom by order of exponents.
    {
        int max = i;
        for (int j = i + 1; j < m_count; j++)
        {
            if (m_pol[max].getExp() < m_pol[j].getExp())
            {
                max = j;
            }
        }
        if (max != i)
        {
            Monomial tmp = m_pol[i];
            m_pol[i] = m_pol[max];
            m_pol[max] = tmp;
        }
    }
}

//----------------------------------------------------------------------//

int Polynomial ::maxExp() const
{
    if (m_pol == nullptr)
        throw "Empty array of monomials";
    int max = 0;
    for (int i = 1; i < m_count; ++i)
        if (m_pol[i].getExp() > m_pol[max].getExp())
            max = i;
    return max;
}

//----------------------------------------------------------------------//

Polynomial &Polynomial::operator>>(const char *str)
{
    char *buff = new char[strlen(str) + 1];
    char *tmpP = nullptr;
    strncpy(buff, str, strlen(str));
    *(buff + strlen(str)) = '\0';
    char tmp[30] = {'\0'};
    char key[] = "+-";
    char sign;
    bool valMinus = false;
    int tmpcoeff = 0;
    int tmpexp = 0;

    if (*buff == '-') //Private case wheres the first char is '-'
    {
        valMinus = true;
        ++buff;
    }

    if (buff && strpbrk(buff, key))
        sign = *(strpbrk(buff, key));
    tmpP = strtok(buff, key);

    while (tmpP) // A loop to make the monoms, which a differ by each sign(+/-).
    {
        buff = strtok(NULL, "\0");
        if (*tmpP == 'x')
        {
            tmpcoeff = 1;
            sscanf(tmpP, "x^%d", &tmpexp);
        }

        if (strpbrk(tmpP, "x") && !strpbrk(tmpP, "^"))
            tmpexp = 1;

        sscanf(tmpP, "%dx^%d", &tmpcoeff, &tmpexp);
        if (valMinus)
        {
            tmpcoeff *= -1;
            valMinus = false;
        }
        if (sign == '-')
            valMinus = true;
        Monomial m1(tmpcoeff, tmpexp);
        (*this) += m1;

        if (buff && strpbrk(buff, key))
            sign = *(strpbrk(buff, key));

        tmpP = strtok(buff, key);
        tmpcoeff = 0;
        tmpexp = 0;
    }
    return *this;
}

//----------------------------------------------------------------------//

Polynomial ::~Polynomial()
{
    delete[] m_pol;
}

//----------------------------------------------------------------------//
