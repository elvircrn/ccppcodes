#include <iostream>
#include <iomanip>
	
using namespace std;
	
template <typename TipElemenata>
struct Matrica {
  int broj_redova, broj_kolona;
  TipElemenata **elementi;
};

template <typename TipElemenata>
void UnistiMatricu(Matrica<TipElemenata> mat) {
  if(mat.elementi == 0) return;
  for(int i = 0; i < mat.broj_redova; i++) delete[] mat.elementi[i];
  delete[] mat.elementi;
}

template <typename TipElemenata>
Matrica<TipElemenata> StvoriMatricu(int broj_redova, int broj_kolona) {
  Matrica<TipElemenata> mat;
  mat.broj_redova = broj_redova; mat.broj_kolona = broj_kolona;
  mat.elementi = new TipElemenata*[broj_redova];
  for(int i = 0; i < broj_redova; i++) mat.elementi[i] = 0;
  try {
    for(int i = 0; i < broj_redova; i++) 
      mat.elementi[i] = new TipElemenata[broj_kolona];  
  }
  catch(...) {
    UnistiMatricu(mat);
    throw;
  }
  return mat;
}

template <typename TipElemenata>
void UnesiMatricu(char ime_matrice, Matrica<TipElemenata> &mat) {
  for(int i = 0; i < mat.broj_redova; i++)
    for(int j = 0; j < mat.broj_kolona; j++) {
      cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
      cin >> mat.elementi[i][j];
    }
}

template <typename TipElemenata>
void IspisiMatricu(const Matrica<TipElemenata> &mat, int sirina_ispisa) {
  for(int i = 0; i < mat.broj_redova; i++) {
    for(int j = 0; j < mat.broj_kolona; j++) 
      cout << setw(sirina_ispisa) << mat.elementi[i][j];
    cout << endl;
  }
}
  
template <typename TipElemenata>
Matrica<TipElemenata> ZbirMatrica(const Matrica<TipElemenata> &m1, 
  const Matrica<TipElemenata> &m2) {
    if(m1.broj_redova != m2.broj_redova 
      || m1.broj_kolona != m2.broj_kolona)
        throw "Matrice nemaju jednake dimenzije!\n";
  Matrica<TipElemenata> m3(StvoriMatricu<TipElemenata>(m1.broj_redova, 
    m1.broj_kolona));
  for(int i = 0; i < m1.broj_redova; i++)
    for(int j = 0; j < m1.broj_kolona; j++)
      m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
  return m3;
}  

int main() {
  Matrica<double> a = {0, 0, 0}, b = {0, 0, 0}, c = {0, 0, 0};
  int m, n;
  cout << "Unesi broj redova i kolona za matrice:\n";
  cin >> m >> n;
  try {
    a = StvoriMatricu<double>(m, n); 
    b = StvoriMatricu<double>(m, n);
    cout << "Unesi matricu A:\n";
    UnesiMatricu('A', a);
    cout << "Unesi matricu B:\n";
    UnesiMatricu('B', b);
    cout << "Zbir ove dvije matrice je:\n";
    IspisiMatricu(c = ZbirMatrica(a, b), 7);
  }
  catch(...) {
    cout << "Nema dovoljno memorije!\n";
  }
  UnistiMatricu(a); UnistiMatricu(b); UnistiMatricu(c);
  return 0;
}
