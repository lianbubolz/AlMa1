#include "fraction.h"
#include <iostream>
#include <stdexcept>

Fraction::Fraction(int p, int q) : m_p(p), m_q(q) {
    if(q == 0)
    {
        throw std::invalid_argument("Nenner kann nicht 0 sein!");
    }
}

    int Fraction::get_p() const { return m_p; }
    int Fraction::get_q() const { return m_q; }

    void Fraction::set_p(int n){  m_p = n; } 
    void Fraction::set_q(int n){ 
        if(n == 0)
        {
            throw std::invalid_argument("Nenner kann nicht 0 sein!");
        }   
        m_q = n;  
        }

    Fraction Fraction::operator-(const Fraction& a){
        int p_a = a.get_p();
        int q_a = a.get_q();
        int zähler = (m_p * q_a) - (p_a * m_q);
        int nenner = q_a * m_q;
        return Fraction(zähler, nenner);
    }

    Fraction Fraction::operator*(const Fraction& a){
        int p_a = a.get_p();
        int q_a = a.get_q();
        int zähler = (m_p) * (p_a);
        int nenner = q_a * m_q;
        return Fraction(zähler, nenner);
    }

    Fraction Fraction::operator/(const Fraction& a){
        int p_a = a.get_p();
        int q_a = a.get_q();
        int zähler = m_p * q_a;
        int nenner = p_a * m_q;
        return Fraction(zähler, nenner);
    }
