struct Rational
{
    Rational(int numerator = 0, int denominator = 1);

     Rational & operator+=(Rational rational)
    {
        (*this).add(rational);
        return *this;
    }
    Rational & operator-=(Rational rational)
    {
        (*this).sub(rational);
        return *this;
    }
    Rational & operator*=(Rational rational)
    {
        (*this).mul(rational);
        return *this;
    }
    Rational & operator/=(Rational rational)
    {
        (*this).div(rational);
        return *this;
    }
    
    Rational  operator-() const{
        Rational temp(numerator_, denominator_);
        temp.neg();
        return temp;
    }
    Rational operator+() const
    {
        Rational temp(numerator_, denominator_);
        return temp;
    }
    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

private:
    int numerator_;
    int denominator_;
};