#include <iostream>
using namespace std;
class Rational {
public:
  Rational() : numerator{0}, denominator{1} {}
  Rational(int a, int b) : numerator(a), denominator(b) {}

  void set_numerator(int a) { numerator = a; }
  void set_denominator(int a) { denominator = a; }
  int get_numerator() const { return numerator; }
  int get_denominator() const { return denominator; }
  Rational &operator=(const Rational &rhs);
  Rational operator*(const Rational &rhs) const;

private:
  int numerator;
  int denominator;
};
/*
Rational::set_numerator(int &a){
    numerator=a;
}
void Rational::set_denominator(int &a){
    denominator=a;
}*/
Rational &Rational::operator=(const Rational &a) {
  // Rational b;
  this->set_numerator(a.get_numerator());
  this->set_denominator(a.get_denominator());
  return *this;
}

Rational Rational::operator*(const Rational &a) const {
  Rational c;
  int m, n;
  m = a.get_numerator() * (this->get_numerator());
  n = a.get_denominator() * (this->get_denominator());
  c.set_denominator(m);
  c.set_denominator(n);
  return c;
}
