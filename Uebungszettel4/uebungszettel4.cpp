/* 4. Implementieren Sie Subtraktion, Multiplikation und Division in der Klasse Fraction. (5 Punkte) */
#include <iostream>
#include "fraction.h"

int main()
{
    Fraction* einhalb = new Fraction(1,3);
    Fraction* EinSechstel = new Fraction(1,6);

    Fraction* ergebnis1 = new Fraction(*einhalb-*EinSechstel);
    std::cout << ergebnis1->get_p() << "/" << ergebnis1->get_q() << "\n";
    
    Fraction* ergebnis2 = new Fraction(*EinSechstel / *einhalb);
    std::cout << ergebnis2->get_p() << "/" << ergebnis2->get_q() << "\n";

    delete einhalb;
    delete EinSechstel;
    delete ergebnis1;
    delete ergebnis2;
}

