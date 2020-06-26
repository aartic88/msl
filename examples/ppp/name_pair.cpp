#include <iostream>
#include <vector>
using namespace std;
class Name_pair {
private:
  vector<string> name;
  vector<double> age;

public:
  void read_names();
  void read_ages();
  // void print();
  void sort();
  friend ostream &operator<<(ostream &out, Name_pair &);
  friend bool operator==(const Name_pair &a, const Name_pair &b);
  friend bool operator!=(const Name_pair &a, const Name_pair &b);
} namePair;
void Name_pair::read_names() {
  string temp;
  for (int i = 0; i < 5; i++) { // while(cin) doesnt work why???
    cin >> temp;
    name.push_back(temp);
  }
}
void Name_pair::read_ages() {
  double temp;
  for (int i = 0; i < 5; i++) {
    cout << name[i] << " ";
    cin >> temp;
    age.push_back(temp);
  }
}
void Name_pair::sort() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (name[i] < name[j]) {
        swap(name[i], name[j]);
        swap(age[i], age[j]);
      }
    }
  }
}
/*void Name_pair::print() {
  for (int i = 0; i < 5; i++) {
    cout << name[i] << "  " << age[i]<<endl;
  }
}*/
ostream &operator<<(ostream &out, Name_pair &np) {
  for (int i = 0; i < 5; i++) {
    out << np.name[i] << "  " << np.age[i] << endl;
  }
  return out;
}
bool operator==(const Name_pair &a, const Name_pair &b){
  return (a.name==b.name && a.age==b.age);
}
bool operator!=(const Name_pair &a, const Name_pair &b){
  return !(a==b);
}


int main() {
  namePair.read_names();
  namePair.read_ages();
  namePair.sort();
  cout << namePair;
}
