#include <iostream>
#include <string>
using namespace std;
class Patron{
    public:
    Patron()=default;
    Patron(string un, string li, double lf)
    :user_name(un),library_ID(li),library_fee(lf){}
    private:
    string user_name, library_ID;
    double library_fee;
};