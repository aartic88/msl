#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
vector<int> input() {
  vector<int> b;
  int c=0;
  for (int i = 0; i < 4; i++) {
    cin >> c;
    b.push_back(c);
  }
  return b;
}
void bullcow(vector<int> a, vector<int> b) {
  int bull = 0, cow = 0;
  for (int i = 0; i < 4; i++) {
    if (a[i] == b[i])
      bull++;
    else {
      int temp = b[i];
     // int erase= a[i];
     // a.erase(a.begin() + i);
      for (int j = 0; j < 4; j++) {
        if (temp == a[j])
          cow++;
      }
      //a.insert(a.begin() + i, erase);
    }
  }
  cout<<"Bull = "<< bull<<" and cow = "<<cow<<endl;
}
int main() {
  vector<int> a;
  for (int i = 0; i < 4; i++)
    a.push_back((int)(rand() % 10));

  vector<int> b;
  do {
    b = input();
    bullcow(a, b);

  } while (a != b);
}
