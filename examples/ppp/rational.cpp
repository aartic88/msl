#include <cmath>
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
  Rational &operator=(const Rational &a);
  Rational operator*(const Rational &a) const;
  Rational operator/(const Rational &a) const;
  double convert_to_double();

private:
  int numerator;
  int denominator;
};
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
  c.set_numerator(m);
  c.set_denominator(n);
  return c;
}
Rational Rational::operator/(const Rational &a) const {
  Rational c;
  int m, n;
  m = a.get_numerator() * (this->get_denominator());
  n = a.get_denominator() * (this->get_numerator());
  c.set_numerator(m);
  c.set_denominator(n);
  return c;
}
Rational operator+(const Rational &a, const Rational &b) {
  // int l=std::lcm(a.get_denominator(),this->get_denominator());
  int x = a.get_numerator() * b.get_denominator();
  int y = a.get_denominator() * b.get_numerator();
  Rational c;
  c.set_numerator(x + y);
  c.set_denominator(a.get_denominator() * b.get_denominator());
  return c;
}
Rational operator-(const Rational &a, const Rational &b) {
  int x = a.get_numerator() * b.get_denominator();
  int y = a.get_denominator() * b.get_numerator();
  Rational c;
  c.set_numerator(x - y);
  c.set_denominator(a.get_denominator() * b.get_denominator());
  return c;
}
int main() {
  Rational a{5, 14};
  Rational b{6, 7};
  Rational c;
  c = b;
  // cout<<c.get_numerator()<<"/"<<c.get_denominator();
  c = a * b;
  cout << "Multiply : " << c.get_numerator() << "/" << c.get_denominator()
       << endl;
  c = a + b;
  cout << "Add : " << c.get_numerator() << "/" << c.get_denominator() << endl;
  c = a - b;
  cout << "Substraction : " << c.get_numerator() << "/" << c.get_denominator()
       << endl;
  c = a / b;
  cout << "Division : " << c.get_numerator() << "/" << c.get_denominator()
       << endl;
  //cout << c.convert_to_double();

}