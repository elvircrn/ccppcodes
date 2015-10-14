#include <iostream>
#include <string>

using namespace std;

class CvorApstraktni {
  virtual void Ispisi(ostream &cout) const = 0;
  friend ostream &operator <<(ostream &cout, const CvorApstraktni &c) {
    c.Ispisi(cout);
    return cout;
  }
};

class CvorAtom : public CvorApstraktni {
  int vrijednost;
  void Ispisi(ostream &cout) const { cout << vrijednost; } 
public:
  CvorAtom(int vrijednost) : vrijednost(vrijednost) {}
};

class CvorUnarni : public CvorApstraktni {
  string operacija;
  CvorApstraktni *operand;
  void Ispisi(ostream &cout) const { 
    cout << "(" << operacija << *operand << ")"; 
  } 
public:
  CvorUnarni(const string &operacija, CvorApstraktni *operand) : 
    operacija(operacija), operand(operand) {}
};

class CvorBinarni : public CvorApstraktni {
  string operacija;
  CvorApstraktni *operand_1, *operand_2;
  void Ispisi(ostream &cout) const { 
    cout << "(" << *operand_1 << operacija << *operand_2 << ")";
  }
public:
  CvorBinarni(const string &operacija, CvorApstraktni *operand_1, 
    CvorApstraktni *operand_2) : operacija(operacija), operand_1(operand_1), 
    operand_2(operand_2) {}
};

int main() {
  CvorBinarni *e(new CvorBinarni("-", new CvorBinarni("*", 
    new CvorAtom(6), new CvorUnarni("-", new CvorAtom(2))), 
    new CvorBinarni("+", new CvorAtom(4), new CvorBinarni("/", 
    new CvorAtom(9), new CvorAtom(3)))));
  cout << *e << endl;
  e = new CvorBinarni("*", e, new CvorBinarni("+", e, new CvorAtom(7)));  
  cout << *e << endl;
  return 0;
}
