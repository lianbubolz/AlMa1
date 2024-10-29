/* Schreiben Sie ein C++-Programm, das für jede Zahl n ∈ {1, . . . , 1000000} die Länge der in
n beginnenden Collatz-Folge berechnet und anschließend ein n∗ ∈ {1, . . . , 1000000} ausgibt,
für das die in n∗ beginnende Collatz-Folge am längsten ist. Geben Sie auch die Länge der
in n∗ beginnenden Collatz-Folge an. Achten Sie darauf, mögliche Überläufe durch geeignete
Abfragen abzufangen. Bei welcher Zahl n genügt der Datentyp short erstmals nicht mehr?

 g++ -std=c++11 -Wall -Wpedantic -o uebungszettel3 uebungszettel3.cpp */

#include <iostream>

int calculateCollatzLength(int startValue);
int maxCollatzLength(int startValue, int endValue);
int maxNumberHit(int startValue);

int main()
{
    int maxLength = maxCollatzLength(1, 1000000);
    std::cout << "Maximale Länge ist " << calculateCollatzLength(maxLength) << " für n=" << maxLength << "\n";

    int iterator = 1;
    while(maxNumberHit(iterator) < 32767)
    {
        iterator++;
    }
    std::cout << "Für n=" << iterator << " reicht der Datentyp short nicht mehr" << "\n";
}

int calculateCollatzLength(int startValue)
{
    unsigned long long n = startValue;
    int length = 0;
    while(n != 1){
        if(n % 2 == 0) {
            n /= 2;
            length++;
        }
        else {
            n = 3*n + 1;
            length++; 
        }
    }
    return length;
}

int maxCollatzLength(int startValue, int endValue)
{  
    int candidate = 0;
    for(int i = startValue; i <= endValue; i++)
    {
        if(candidate < calculateCollatzLength(i))   candidate = i;
    }
    return candidate;
}

int maxNumberHit(int startValue)
{
    unsigned long long n = startValue;
    int maxNumber = startValue;
    while(n != 1){
        if(n > maxNumber) maxNumber = n;
        if(n % 2 == 0) {
            n /= 2;
        }
        else {
            n = 3*n + 1;
        }
    }
    return maxNumber;
}




