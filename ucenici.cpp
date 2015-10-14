#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int BrojPredmeta(12);         // Smanjiti ovaj broj pri eksperimentiranju

struct Datum {
  int dan, mjesec, godina;
};

struct Ucenik {
  string ime, prezime;
  Datum datum_rodjenja;
  int ocjene[BrojPredmeta];
  double prosjek;
  bool prolaz;
};

int main() {
  void UnesiUcenike(vector<Ucenik> &ucenici);
  void ObradiUcenike(vector<Ucenik> &ucenici);
  void IspisiIzvjestaj(const vector<Ucenik> &ucenici);
  int broj_ucenika;
  cout << "Koliko ima ucenika: ";
  cin >> broj_ucenika;
  try {
    vector<Ucenik> ucenici(broj_ucenika);
    UnesiUcenike(ucenici);
    ObradiUcenike(ucenici);
    IspisiIzvjestaj(ucenici);
  }
  catch(...) {
    cout << "Problemi sa memorijom...\n";
  }
  return 0;
}

void UnesiUcenike(vector<Ucenik> &ucenici) {
  void UnesiJednogUcenika(Ucenik &ucenik);
  for(int i = 0; i < ucenici.size(); i++) {
    cout << "Unesite podatke za " << i + 1 << ". ucenika:\n";
    UnesiJednogUcenika(ucenici[i]);
  }
}

void UnesiJednogUcenika(Ucenik &ucenik) {
  void UnesiDatum(Datum &datum);
  void UnesiOcjene(int ocjene[], int broj_predmeta);
  cout << "  Ime: "; cin >> ucenik.ime;
  cout << "  Prezime: "; cin >> ucenik.prezime;
  cout << "  Datum rodjenja (D/M/G): ";
  UnesiDatum(ucenik.datum_rodjenja);
  UnesiOcjene(ucenik.ocjene, BrojPredmeta);
}

void UnesiDatum(Datum &datum) {
  char znak;
  cin >> datum.dan >> znak >> datum.mjesec >> znak >> datum.godina;
}

void UnesiOcjene(int ocjene[], int broj_predmeta) {
  for(int i = 0; i < broj_predmeta; i++) {
    cout << "  Ocjena iz " << i + 1 << ". predmeta: ";
    cin >> ocjene[i];
  }
}

void ObradiUcenike(vector<Ucenik> &ucenici) {
  void ObradiJednogUcenika(Ucenik &ucenik);
  bool DaLiJeBoljiProsjek(const Ucenik &u1, const Ucenik &u2);
  for(int i = 0; i < ucenici.size(); i++) 
    ObradiJednogUcenika(ucenici[i]);
  sort(ucenici.begin(), ucenici.end(), DaLiJeBoljiProsjek);
}

void ObradiJednogUcenika(Ucenik &ucenik) {
  double suma_ocjena(0);
  ucenik.prosjek = 1; ucenik.prolaz = false;
  for(int i = 0; i < BrojPredmeta; i++) {
    if(ucenik.ocjene[i] == 1) return;
    suma_ocjena += ucenik.ocjene[i];
  }
  ucenik.prolaz = true; 
  ucenik.prosjek = suma_ocjena / BrojPredmeta;
}

bool DaLiJeBoljiProsjek(const Ucenik &u1, const Ucenik &u2) {
  return u1.prosjek > u2.prosjek;
}

void IspisiIzvjestaj(const vector<Ucenik> &ucenici) {
  void IspisiJednogUcenika(const Ucenik &ucenik);
  cout << endl;
  for(int i = 0; i < ucenici.size(); i++)
    IspisiJednogUcenika(ucenici[i]);
}

void IspisiJednogUcenika(const Ucenik &ucenik) {
  void IspisiDatum(const Datum &datum);
  cout << "Ucenik " << ucenik.ime << " " << ucenik.prezime << " rodjen ";
  IspisiDatum(ucenik.datum_rodjenja);
  if(ucenik.prolaz) 
    cout << " ima prosjek " << setprecision(3) << ucenik.prosjek;
  else 
    cout << " mora ponavljati razred";
  cout << endl;
}

void IspisiDatum(const Datum &datum) {
  cout << datum.dan << "." << datum.mjesec << "." << datum.godina;
}
