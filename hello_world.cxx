#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
void to_lower(char *s) {
  for (int i = 0; i < 15; i++) {
    if (s[i] > 64 && s[i] < 91) {
      s[i] = int(s[i] + 32);
    }
  }
  cout << s;
}

int main() {
  char str[] = "Hello World!!";
  char *s = str;
  cout << s << endl;
  to_lower(s);
}*/
//char *strdup(const char *s) {}
int main() {
  //char str[] = "Hello World!!";
char *s = new char[20]{'f','s','d','g'};
  //s = str;
  cout<<s;
  delete [] s;
}