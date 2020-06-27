#include <iostream>
#include <string>
using namespace std;
enum Genre { fiction, nonfiction, periodical, biography, children };
class Book {
public:
  Book() = default;
  Book(string ISBN, string title, string author, Genre gen)
      : ISBN(ISBN), title(title), author(author), gen(gen) {}
  bool checking_status() { return book_status; }
  bool valid_ISBN(const Book &);
  //Genre genre() const { return gen; }
  friend ostream &operator<<(ostream &out, const Book &);
  friend bool operator==(const Book &a, const Book &b);
  friend bool operator!=(const Book &a, const Book &b);

private:
  string ISBN, title, author, copyright_date;
  bool book_status;
  Genre gen;
};
// check validity of ISBN form n-n-n-x where
// n is integer, x is either integer or letter.
bool Book::valid_ISBN(const Book &b) {
  int count = 0;
  for (auto c : b.ISBN) {
    if (c == '-') {
      count++;
    } else {
      if (count < 3) {
        if (!isdigit(c))
          return false;
      } else {
        if (!(isdigit(c) || isalpha(c)))
          return false;
      }
    }
  }
  return true;
}
ostream &operator<<(ostream &out, const Book &b) {
  out << b.title << " " << b.author << " " << b.ISBN << " " << b.gen;
  return out;
}
bool operator==(const Book &a, const Book &b) {
  return (a.title == b.title && a.author == b.author 
  && a.ISBN == b.ISBN && a.gen==b.gen);
}
bool operator!=(const Book &a, const Book &b) { return !(a == b); }

/* -----------PATRON CLASS-----------------*/

int main() {
  Book book{"124-224-432-4h3", "C++", "Bjarne", Genre::nonfiction};
  // Book book1{"124-224-432-4h3", "C++", "Bjarne"};
  // Book book2{"124-224-432-4h3", "Data base", "goodrich"};
  cout << book.valid_ISBN(book) << endl;
  cout << book << endl;
}