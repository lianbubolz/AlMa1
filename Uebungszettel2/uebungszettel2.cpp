/*Schreiben Sie ein C++-Programm, das alle Primzahlzwillinge (also Paare von Primzahlen,
deren Differenz 2 ist) auflistet, die kleiner als 10^6 sind. Wie viele gibt es? 

g++ -std=c++11 -Wall -Wpedantic -o uebungszettel2  uebungszettel2.cpp
*/

#include <iostream>
#include <vector>

std::vector<bool> siebDesEratosthenes(int n);
void primAbstand(std::vector<bool>& isPrime, int dif);
int bisZahl = 1000*1000;

int main()
{
    int abstand = 2;

    std::vector<bool> primzahlen = siebDesEratosthenes(bisZahl);
    primAbstand(primzahlen, abstand);

    return 0;
} 


std::vector<bool> siebDesEratosthenes(int n)
{
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = true;
    isPrime[1] = true;

    for (int j = 2; j * j <= n; j++) 
    {
        if (isPrime[j]) 
        {
            for (int k = j * j; k <= n; k += j)
                isPrime[k] = false;
        }
    } 
    return isPrime;
}

void primAbstand(std::vector<bool>& primes, int dif)
{
    int counter = 0;
    for(size_t i = 0; i < (primes.size() - 1); i++)
    {
        if(primes[i] && primes[i+dif]) 
        {
            std::cout << "("<< i <<", " << (i+dif) <<") ";
            counter++;
        }
    }
    std::cout << "\n\nEs gibt " << counter << " Primzahlen mit Abstand " << dif << " für das Intervall (0," << bisZahl << ").";
}
