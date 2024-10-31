#ifndef FRACTION
#define FRACTION

class Fraction 
{
    private:
        int m_p;
        int m_q;

        

    public:
        Fraction(int p, int q);

        int get_p() const;
        int get_q() const;

        void set_p(int n);   
        void set_q(int n);

        Fraction operator-(const Fraction& a);
        Fraction operator*(const Fraction& a);
        Fraction operator/(const Fraction& a);

};

#endif