#include "Monomial.h"
//----------------------------------------------------------------------//

Monomial::Monomial() : m_coeff(0), m_exp(0) {}

//----------------------------------------------------------------------//

Monomial::Monomial(int coeff, int exp)
{
    if (exp < 0)
        throw "Only natural numbers for exponent";
    m_exp = exp;
    m_coeff = coeff;
}

//----------------------------------------------------------------------//

int Monomial::getCoeff() const { return m_coeff; }

//----------------------------------------------------------------------//

int Monomial::getExp() const { return m_exp; }

//----------------------------------------------------------------------//

const Monomial &Monomial::operator+=(const Monomial &x)
{
    if (m_exp != x.m_exp)
        throw "Cannot add different exponents";
    m_coeff += x.m_coeff;

    return *this;
}

//----------------------------------------------------------------------//

Monomial Monomial::operator*(const Monomial &x)
{
    Monomial y = *this;

    return y *= x;
}

//----------------------------------------------------------------------//

const Monomial &Monomial::operator*=(const Monomial &x)
{
    m_coeff *= x.m_coeff;
    m_exp += x.m_exp;
    return *this;
}

//----------------------------------------------------------------------//

bool Monomial::operator==(const Monomial &x) const
{
    if (m_exp != x.m_exp || m_coeff != x.m_coeff)
        return false;
    return true;
}

//----------------------------------------------------------------------//

void Monomial::negate()
{
    m_coeff *= (-1);
}

//----------------------------------------------------------------------//

ostream &operator<<(ostream &out, const Monomial &m)
{
    out << m.stringRepresentation();

    return out;
}

//----------------------------------------------------------------------//

char *Monomial::stringRepresentation() const
{
    char *str = nullptr;
    char *buff = nullptr;
    bool flag = false;
    int temp = m_coeff;

    if (temp < 0)
    {
        temp *= -1;
        flag = true;
    }

    if (temp == 0 || m_exp == 0)
        str = intToString(temp);

    else if ((temp == 1) && (m_exp == 1))
    {
        str = intToString(temp);
        *(str) = 'x';
    }
    else
    {
        int size = 0;
        int size2 = 0;
        str = new char[2];
        if (temp != 1)
        {
            buff = intToString(temp);
            size = strlen(buff);
            str = (char *)realloc(str, size + 2);
            strncpy(str, buff, size);
            delete[] buff;
        }
        *(str + size) = 'x';
        if (m_exp != 1)
        {
            *(str + size + 1) = '^';
            buff = intToString(m_exp);
            size2 = strlen(buff) + 1;
            str = (char *)realloc(str, size + size2 + 3);
            strncpy(str + size + 2, buff, size2);
            delete[] buff;
        }
        *(str + size + size2 + 1) = '\0';
    }

    if (flag) //Put a (-) sign in the beggining of the array if neede
    {
        int size = strlen(str);
        buff = new char[size + 2];
        *(buff) = '-';
        strncpy(buff + 1, str, size);
        delete[] str;
        *(buff + size + 1) = '\0';
        str = buff;
    }

    return str;
}

//----------------------------------------------------------------------//

char *intToString(int num)
{
    int i = 0;
    int tmp = num;
    for (; num > 0; num /= 10)
        ++i;
    char *str = new char[i + 1];
    sprintf(str, "%d", tmp);
    return str;
}

//----------------------------------------------------------------------//
