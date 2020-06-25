#include "Polynomial.h"

int main()
{
    Monomial m1(4, 5);
    Monomial m2(1,3);
    Polynomial p1;
    Polynomial p2;

    p1 += m1;
    cout << p1 << endl;
    
    p1 += p1;
    cout << p1 << endl;

    p1 = m2 + p1;
        cout << p1 << endl;

    p2 >> "2x^5 -6 + 3x^7";
    cout<< p2 << endl;

    p2 += p1;
    cout << p2 <<endl;

    
}