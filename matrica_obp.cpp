#include <iostream>
#include <iomanip>
#include <cstring>
	
using namespace std;
		
template <typename TipEl>
class Matrica {
  int br_redova, br_kolona;
  TipEl **elementi;
  char ime_matrice;
  void AlocirajMemoriju(int br_redova, int br_kolona);
  void DealocirajMemoriju();
public:
  Matrica(int br_redova, int br_kolona, char ime = 0);
  Matrica(const Matrica &m);
  ~Matrica() { DealocirajMemoriju(); }
  Matrica &operator =(const Matrica &m);
  void Unesi();
  void Ispisi(int sirina_ispisa) const;
  template <typename Tip2>
  friend Matrica<Tip2> ZbirMatrica(const Matrica<Tip2> &m1, 
    const Matrica<Tip2> &m2);
};

template <typename TipEl>
void Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona) {
  elementi = new TipEl*[br_redova];
  for(int i = 0; i < br_redova; i++) elementi[i] = 0;
  try {
    for(int i = 0; i < br_redova; i++) 
      elementi[i] = new TipEl[br_kolona];
  }
  catch(...) {
    DealocirajMemoriju();
    throw;
  }
}

template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju() {
  for(int i = 0; i < br_redova; i++) delete[] elementi[i];
  delete[] elementi;
}

template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) :
  br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime) {
    AlocirajMemoriju(br_redova, br_kolona);
}

template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova),
  br_kolona(m.br_kolona), ime_matrice(m.ime_matrice) {
    AlocirajMemoriju(br_redova, br_kolona);
    for(int i = 0; i < br_redova; i++)
      for(int j = 0; j < br_kolona; j++)
        elementi[i][j] = m.elementi[i][j];
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m) {
  if(br_redova < m.br_redova || br_kolona < m.br_kolona) {
    DealocirajMemoriju(); AlocirajMemoriju(m.br_redova, m.br_kolona);
  }
  else if (br_redova > m.br_redova)
    for(int i = m.br_redova; i < br_redova; i++) delete elementi[i];
  ime_matrice = m.ime_matrice; 
  br_redova = m.br_redova; br_kolona = m.br_kolona;
  for(int i = 0; i < br_redova; i++)
    for(int j = 0; j < br_kolona; j++)
      elementi[i][j] = m.elementi[i][j];
  return *this;
}

template <typename TipEl>
void Matrica<TipEl>::Unesi() {
  for(int i = 0; i < br_redova; i++)
    for(int j = 0; j < br_kolona; j++) {
      cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
      cin >> elementi[i][j];
    }
}

template <typename TipEl>
void Matrica<TipEl>::Ispisi(int sirina_ispisa) const {
  for(int i = 0; i < br_redova; i++) {
    for(int j = 0; j < br_kolona; j++)
      cout << setw(sirina_ispisa) << elementi[i][j];
    cout << endl;
  }
}
  
template <typename TipEl>
Matrica<TipEl> ZbirMatrica(const Matrica<TipEl> &m1, 
  const Matrica<TipEl> &m2) {
    if(m1.br_redova != m2.br_redova || m2.br_redova != m2.br_redova)
        throw "Matrice nemaju jednake dimenzije!\n";
    Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
    for(int i = 0; i < m1.br_redova; i++)
      for(int j = 0; j < m1.br_kolona; j++)
        m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
    return m3;
}

int main() {
  int m, n;
  cout << "Unesi broj redova i kolona za matrice:\n";
  cin >> m >> n;
  try {
    Matrica<double> a(m, n, 'A'), b(m, n, 'B');
    cout << "Unesi matricu A:\n";
    a.Unesi();
    cout << "Unesi matricu B:\n";
    b.Unesi();
    cout << "Zbir ove dvije matrice je:\n";
    ZbirMatrica(a, b).Ispisi(7);
  }
  catch(...) {
    cout << "Nema dovoljno memorije!\n";
  }
  return 0;
}
