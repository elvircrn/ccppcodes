#include <iostream>
#include <string>

using namespace std;

class CvorApstraktni {
  int brojac;
  virtual void Ispisi(ostream &cout) const = 0;
protected:
  CvorApstraktni() : brojac(1) {}
  virtual ~CvorApstraktni() {}
  friend class Izraz;
  friend ostream &operator <<(ostream &cout, const Izraz &e);
};

class Izraz {
  CvorApstraktni *korijen;
public:
  Izraz(int vrijednost);
  Izraz(const string &operacija, Izraz operand);
  Izraz(const string &operacija, Izraz operand_1, Izraz operand_2);
  ~Izraz();
  Izraz(const Izraz &e);
  Izraz &operator =(const Izraz &e);
  friend ostream &operator <<(ostream &cout, const Izraz &e) {
    e.korijen->Ispisi(cout);
    return cout;  
  }
};

class CvorAtom : public CvorApstraktni {
  int vrijednost;
  void Ispisi(ostream &cout) const { cout << vrijednost; } 
  CvorAtom(int vrijednost) : vrijednost(vrijednost) {}
  friend class Izraz;
};

class CvorUnarni : public CvorApstraktni {
  string operacija;
  Izraz operand;
  void Ispisi(ostream &cout) const { 
    cout << "(" << operacija << operand << ")"; 
  } 
  CvorUnarni(const string &operacija, Izraz operand) : 
    operacija(operacija), operand(operand) {}
  friend class Izraz;
};

class CvorBinarni : public CvorApstraktni {
  string operacija;
  Izraz operand_1, operand_2;
  void Ispisi(ostream &cout) const { 
    cout << "(" << operand_1 << operacija << operand_2 << ")";
  }
  CvorBinarni(const string &operacija, Izraz operand_1, Izraz operand_2) : 
    operacija(operacija), operand_1(operand_1), operand_2(operand_2) {}
  friend class Izraz;
};

Izraz::Izraz(int vrijednost) : korijen(new CvorAtom(vrijednost)) {}

Izraz::Izraz(const string &operacija, Izraz operand) : 
  korijen(new CvorUnarni(operacija, operand)) {}
  
Izraz::Izraz(const string &operacija, Izraz operand_1, Izraz operand_2) : 
  korijen(new CvorBinarni(operacija, operand_1, operand_2)) {}  

Izraz::Izraz(const Izraz &e) : korijen(e.korijen) { 
  (korijen->brojac)++; 
}

Izraz::~Izraz() {
  if(--(korijen->brojac) == 0) delete korijen;
}

Izraz &Izraz::operator =(const Izraz &e) {
  (e.korijen->brojac)++;
  if(--(korijen->brojac) == 0) delete korijen;
  korijen = e.korijen;
  return *this;
}

int main() {
  Izraz e(Izraz("-", Izraz("*", 6, Izraz("-", 2)), Izraz("+", 4, 
    Izraz("/", 9, 3))));
  cout << e << endl;
  e = Izraz("*", e, Izraz("+", e, 7));  
  cout << e << endl;
  return 0;
}
