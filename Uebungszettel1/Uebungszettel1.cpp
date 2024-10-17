/* Schreiben Sie ein C++-Programm, das drei positive ganze Zahlen einliest, welche die Breite,
Höhe und Tiefe eines Quaders angeben sollen. Geben Sie anschließend das Volumen des Qua-
ders aus. */


#include <iostream>

// Funktionsdeklarierung
int volumenBerechnen(unsigned int length, unsigned int height, unsigned int depth);
unsigned int input(const std::string& maße);

int main()
{

    std::cout << "Geben sie Laenge, Hoehe und Tiefe des Quaders an" << std::endl;
    unsigned int laenge = input("Laenge");
    unsigned int hoehe = input("Hoehe");
    unsigned int tiefe = input("Tiefe");

    std::cout << "Volumen des Quaders ist " << volumenBerechnen(laenge, hoehe, tiefe) << std::endl;

    return 0;
}

// Funktion zur korrekten Übergabe der Quader-Maße
unsigned int input(const std::string& maße)
{
    int measurement = 0;
    while(true)
    {
        std::cout << maße << ": " << std::endl;
        std::cin >> measurement;
        if(measurement < 0)
        {
            std::cout << "Nur nicht-negative Maße angeben!" << std::endl;
        } else { 
            break;
        }
    }   
    return measurement;
}

// Funktion zur Berechnung des Volumen
int volumenBerechnen(unsigned int length, unsigned int height, unsigned int depth)
{
    return length * height * depth;
}
