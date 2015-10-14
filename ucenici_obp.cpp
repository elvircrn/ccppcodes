#include <iostream>
#include <cstring>
#include <iomanip>
#include <algorithm>

using namespace std;

class Datum {
  int dan, mjesec, godina;
public:
  Datum(int d, int m, int g);
  void Unesi();
  void Ispisi() const { cout << dan << "." << mjesec << "." << godina; }
};

class Ucenik {
  static const int BrojPredmeta = 12;   // Pri testiranju smanjite ovaj broj
  char ime[20], prezime[20];
  Datum datum_rodjenja;
  int ocjene[BrojPredmeta];
  double prosjek;
  bool prosao;
public:
  Ucenik(const char ime[], const char prezime[], int d, int m, int g);
  void PostaviOcjenu(int predmet, int ocjena);
  static int DajBrojPredmeta() { return BrojPredmeta; }
  double DajProsjek() const { return prosjek; }
  bool DaLiJeProsao() const { return prosao; }
  void Ispisi() const;
};

class Razred {
  const int kapacitet;
  int broj_evidentiranih;
  Ucenik **ucenici;
  static bool BoljiProsjek(const Ucenik *u1, const Ucenik *u2) {
    return u1->DajProsjek() > u2->DajProsjek();
  }
public:
  explicit Razred(int broj_ucenika) : kapacitet(broj_ucenika),
     broj_evidentiranih(0), ucenici(new Ucenik*[broj_ucenika]) {}
  ~Razred();
  void EvidentirajUcenika(Ucenik *ucenik);
  void UnesiNovogUcenika();
  void IspisiIzvjestaj() const;
  void SortirajUcenike() { 
    sort(ucenici, ucenici + broj_evidentiranih, BoljiProsjek); 
  }
};

int main() {
  try {
    int broj_ucenika;
    cout << "Koliko ima ucenika: ";
    cin >> broj_ucenika;
    if(!cin) throw 0;               // Ovdje je nebitno ?ta bacamo...
    Razred razred(broj_ucenika);
    for(int i = 1; i <= broj_ucenika; i++) {
      cout << "Unesi podatke za " << i << " ucenika:\n";
      razred.UnesiNovogUcenika();
    }
    razred.SortirajUcenike();
    razred.IspisiIzvjestaj();
  }
  catch(...) {
    cout << "Problemi sa memorijom!\n";
  }
  return 0;
}

Datum::Datum(int d, int m, int g) {
  int broj_dana[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if(g % 4 == 0 && g % 100 != 0 || g % 400 == 0) broj_dana[1]++;
  if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1])
    throw "Neispravan datum!";
  dan = d; mjesec = m; godina = g;
}

Ucenik::Ucenik(const char ime[], const char prezime[],  int d, int m, int g) : 
  datum_rodjenja(d, m, g), prosjek(1), prosao(false) {
    if(strlen(ime) > 19 || strlen(prezime) > 19)
      throw "Predugacko ime ili prezime!";
    strcpy(Ucenik::ime, ime); strcpy(Ucenik::prezime, prezime);
    for(int i = 0; i < BrojPredmeta; i++) ocjene[i] = 1;
}

void Ucenik::PostaviOcjenu(int predmet, int ocjena) {
  if(ocjena < 1 || ocjena > 5) throw "Pogresna ocjena!";
  if(predmet < 1 || predmet > BrojPredmeta) 
    throw "Pogresan broj predmeta!";
  ocjene[predmet - 1] = ocjena;
  prosjek = 1; prosao = false;
  double suma_ocjena(0);
  for(int i = 0; i < BrojPredmeta; i++) {
    if(ocjene[i] == 1) return;
    suma_ocjena += ocjene[i];
  }
  prosjek = suma_ocjena / BrojPredmeta; prosao = true;
}

void Ucenik::Ispisi() const {
  cout << "Ucenik " << ime << " " << prezime << " rodjen ";
  datum_rodjenja.Ispisi();
  if(DaLiJeProsao())
    cout << " ima prosjek " << setprecision(3) << DajProsjek() << endl;
  else
    cout << " mora ponavljati razred\n";
}

Razred::~Razred() {
  for(int i = 0; i < broj_evidentiranih; i++) delete ucenici[i];
  delete[] ucenici; 
}

void Razred::EvidentirajUcenika(Ucenik *ucenik) {
  if(broj_evidentiranih >= kapacitet) throw "Previse ucenika!";
  ucenici[broj_evidentiranih++] = ucenik;
}

void Razred::UnesiNovogUcenika() {
  bool pogresan_unos(true);
  while(pogresan_unos) {
    try {
      char ime[20], prezime[20];
      int d, m, g;
      char znak1, znak2;
      cout << "  Ime: "; cin >> setw(20) >> ime;
      cout << "  Prezime: "; cin >> setw(20) >> prezime;
      cout << "  Datum rodjenja (D/M/G): ";
      cin >> d >> znak1 >> m >> znak2 >> g;
      if(!cin || znak1 != '/' || znak2 != '/') throw "Pogresan datum!";
      Ucenik *ucenik = new Ucenik(ime, prezime, d, m, g);
      for(int pr = 1; pr <= Ucenik::DajBrojPredmeta(); pr++) {
        int ocjena;
        cout << "  Ocjena iz " << pr << ". predmeta: ";
        cin >> ocjena;
        if(!cin) throw "Pogresna ocjena!";
        ucenik->PostaviOcjenu(pr, ocjena);
      }
      EvidentirajUcenika(ucenik);
      pogresan_unos = false;
    }
    catch(const char greska[]) {
      cout << "Greska: " << greska << "\nMolimo, ponovite unos!\n";
      cin.clear(); cin.ignore(10000, '\n');
    }
  }
}

void Razred::IspisiIzvjestaj() const {
  cout << endl;
  for(int i = 0; i < broj_evidentiranih; i++)
    ucenici[i]->Ispisi();
}
