#include <iostream>
#include <string>

using namespace std;

class CvorApstraktni {
  int brojac;
  virtual void Ispisi(ostream &cout) const = 0;
  virtual int Izracunaj() const = 0;
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
  int Izracunaj() const { return korijen->Izracunaj(); }
};

class CvorAtom : public CvorApstraktni {
  int vrijednost;
  void Ispisi(ostream &cout) const { cout << vrijednost; } 
  CvorAtom(int vrijednost) : vrijednost(vrijednost) {}
  int Izracunaj() const { return vrijednost; }
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
  int Izracunaj() const;
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
  int Izracunaj() const;
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

int CvorUnarni::Izracunaj() const {
  int vrijednost(operand.Izracunaj());
  if(operacija == "-") return -vrijednost;
  if(operacija == "!") return (vrijednost == 0) ? 1 : 0;
  throw "Nepoznata unarna operacija!\n";
}

int CvorBinarni::Izracunaj() const {
  int vrijednost_1(operand_1.Izracunaj());
  int vrijednost_2(operand_2.Izracunaj());
  if(operacija == "+") return vrijednost_1 + vrijednost_2;
  if(operacija == "-") return vrijednost_1 - vrijednost_2;
  if(operacija == "*") return vrijednost_1 * vrijednost_2;
  if(operacija == "/") {
    if(vrijednost_2 == 0) throw "Dijeljenje nulom!";
    return vrijednost_1 / vrijednost_2;
  }
  throw "Nepoznata binarna operacija!\n";
}

int main() {
  Izraz e(Izraz("*", Izraz("-", 5), Izraz("+", 3, 4)));
  cout << e << " = " << e.Izracunaj() << endl;
  e = Izraz("*", e, e);
  cout << e << " = " << e.Izracunaj() << endl;
  return 0;
}
