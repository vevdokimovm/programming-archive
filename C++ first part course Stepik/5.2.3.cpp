struct Rational
{
    Rational(int numerator = 0, int denominator = 1);

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;

    Rational& operator+=(Rational rational);
    Rational& operator-=(Rational rational);
    Rational& operator*=(Rational rational);
    Rational& operator/=(Rational rational);
                
    Rational operator-() const;
    Rational operator+() const;
    
    int get_numerator() const { return numerator_; };
    int get_denominator() const { return denominator_; };
                
private:
    int numerator_;
    int denominator_;
};

    bool operator>(Rational const & rational1, Rational const & rational2){
        return ((rational1.get_numerator() * rational2.get_denominator()) > (rational2.get_numerator() * rational1.get_denominator()));
    }
    bool operator<(Rational const & rational1, Rational const & rational2){
        return rational2 > rational1;
    }
    bool operator>=(Rational const & rational1, Rational const & rational2){
        return !(rational2 > rational1);
    }
    bool operator<=(Rational const & rational1, Rational const & rational2){
        return !(rational1 > rational2);
    }
    bool operator==(Rational const & rational1, Rational const & rational2){
        return !(rational1 > rational2) && !(rational2 > rational1);
    }
    bool operator!=(Rational const & rational1, Rational const & rational2){
        return !(rational2 == rational1); 
    }

Rational operator+(Rational lhs, Rational rhs);
Rational operator-(Rational lhs, Rational rhs);
Rational operator*(Rational lhs, Rational rhs);
Rational operator/(Rational lhs, Rational rhs);