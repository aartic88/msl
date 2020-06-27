#include <iostream>
#include <string>
using namespace std;
class Patron {
public:
  Patron() = default;
  Patron(string un, string li, double lf)
      : user_name(un), library_ID(li), library_fee(lf) {}
  string get_user_name() const { return user_name; }
  string get_library_ID() const{ return library_ID; }
  double get_library_fee() const { return library_fee; }
  void set_library_fee();

private:
  string user_name, library_ID;
  double library_fee;
};
void Patron::set_library_fee(){
    cin>>library_fee;
}
bool fee_owed(Patron &p) {
  if (p.get_library_fee() > 0) {
    return true;
  } else {
    return false;
  }
}
ostream & operator<<(ostream &out, const Patron &p) {
  return out << p.get_user_name()<<" "<<p.get_library_ID()<<" "<<
          p.get_library_fee();
}
int main(){
    Patron patron{"Aarti","mat201234",0.0};
    patron.set_library_fee();
    cout<<patron<<endl;
    cout<<fee_owed(patron);

}
