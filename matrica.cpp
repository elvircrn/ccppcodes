#include <iostream>
#include <vector>

using namespace std;

// Kreira matricu sa zadanim brojem redova i kolona
vector<vector<double> > KreirajMatricu(int br_redova, int br_kolona) {
  vector<vector<double> > m(br_redova, vector<double>(br_kolona));
  return m;                        
}

// Vraca broj redova zadane matrice
int BrojRedova(vector<vector<double> > m) {
  return m.size();   
}

// Vraca broj kolona zadane matrice
int BrojKolona(vector<vector<double> > m) {
  return m[0].size();   
}

// Unosi sa tastature matricu sa zadanim brojem redova i kolona i
// vraca je kao rezultat
vector<vector<double> > UnesiMatricu(int br_redova, int br_kolona) {
  vector<vector<double> > m(KreirajMatricu(br_redova, br_kolona));
  for(int i = 0; i < br_redova; i++)
    for(int j = 0; j < br_kolona; j++) {
      cout << "Element (" << i + 1 << "," << j + 1 << "): ";
      cin >> m[i][j];      
    }
  return m;                        
}

// Ispisuje zadanu matricu
void IspisiMatricu(vector<vector<double> > m) {
  for(int i = 0; i < BrojRedova(m); i++) {
    for(int j = 0; j < BrojKolona(m); j++) {
      cout.width(10);
      cout << m[i][j];
    }      
    cout << endl;
  }
}

// Testira da li su dvije matrice saglasne za sabiranje
bool MoguSeSabirati(vector<vector<double> > m1, vector<vector<double> > m2) {
    return (BrojRedova(m1) == BrojRedova(m2)) 
      && (BrojKolona(m1) == BrojKolona(m2));    
}

// Vraca zbir zadanih matrica, uz pretpostavku da su saglasne za sabiranje
vector<vector<double> > SaberiMatrice(vector<vector<double> > m1,
  vector<vector<double> > m2) {
  	vector<vector<double> > m3(KreirajMatricu(BrojRedova(m1), BrojKolona(m1)));
    for(int i = 0; i < BrojRedova(m1); i++)
      for(int j = 0; j < BrojKolona(m1); j++)
        m3[i][j] = m1[i][j] + m2[i][j];
    return m3;
}

// Testira da li su dvije matrice saglasne za mnozenje
bool MoguSeMnoziti(vector<vector<double> > m1, vector<vector<double> > m2) {
  return BrojKolona(m1) == BrojRedova(m2);    
}

// Vraca produkt zadanih matrica, uz pretpostavku da su 
// saglasne za mnozenje
vector<vector<double> > PomnoziMatrice(vector<vector<double> > m1,
  vector<vector<double> > m2) {
    vector<vector<double> > m3(KreirajMatricu(BrojRedova(m1), BrojKolona(m2)));
    for(int i = 0; i < BrojRedova(m1); i++)
      for(int j = 0; j < BrojKolona(m2); j++) {
        double suma(0);
        for(int k = 0; k < BrojRedova(m2); k++)
          suma += m1[i][k] * m2[k][j];
        m3[i][j] = suma;
      }
    return m3;
}

// Glavni program
int main() {
  int m1, n1;
  cout << "Unesi dimenzije matrice A: ";
  cin >> m1 >> n1;
  cout << "Unesi elemente matrice A:\n";
  vector<vector<double> > A(UnesiMatricu(m1, n1));
  int m2, n2;
  cout << "Unesi dimenzije matrice B: ";
  cin >> m2 >> n2;
  cout << "Unesi elemente matrice B:\n";
  vector<vector<double> > B(UnesiMatricu(m2, n2));
  cout << "Matrica A:\n";
  IspisiMatricu(A);
  cout << "Matrica B:\n";
  IspisiMatricu(B);
  if(MoguSeSabirati(A, B)) {
    cout << "Matrica A+B:\n";
    IspisiMatricu(SaberiMatrice(A, B));                   
  }
  else cout << "Matrice nisu saglasne za sabiranje!\n";
  if(MoguSeMnoziti(A, B)) {
    cout << "Matrica A*B:\n";
    IspisiMatricu(PomnoziMatrice(A, B));                   
  }
  else cout << "Matrice nisu saglasne za mnozenje!\n";
  return 0;
}
