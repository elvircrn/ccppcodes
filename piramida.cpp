#include <vector>
#include <iostream>

using namespace std;

int vratiNajveciPodniz(vector<int> lista) {
    int praviMax = lista[0];
    int sadasnjiMax = lista[0];
    for (int i = 1; i < lista.size(); i++) {
        if (sadasnjiMax < 0) {
            sadasnjiMax = lista[i];
        } else {
            sadasnjiMax += lista[i];
        }

        if (sadasnjiMax > praviMax) {
            praviMax = sadasnjiMax;
        }
    }
    return praviMax;
}

int vratiIndexMaxElementa(vector<int> lista) {
    int index = 0;
    for (int i = 1; i < lista.size(); i++) {
        if (lista[index] < lista[i]) {
            index = i;
        }
    }
    return index;
}

int vratiIndexMaxElementaSaPrioritetom(vector<int> lista, vector<int> listaRazlike) {
    int index = 0;
    for (int i = 1; i < lista.size(); i++) {
        if (lista[index] < lista[i] || (lista[index] == lista[i] && listaRazlike[index] < listaRazlike[i])) {
            index = i;
        }
    }
    return index;
}

int vratiMaxBodove(int n, int k, int p, int s, vector<vector<int> > lista) {
    vector<vector<int> > lista1;
    vector<vector<int> > lista2;
    vector<int> listaMax1;
    vector<int> listaMax2;
    vector<int> listaRazlike;
    vector<int> listaS;
    for (int i = 0; i < n; i++) {
        vector<int> temp1;
        vector<int> temp2;
        for (int j = 0; j < k / 2; j++) {
            int polovina1 = lista[i][j];
            int polovina2 = lista[i][k - 1 - j];
            temp1.push_back(polovina1 + polovina2);
            temp2.push_back((polovina1 == s? 2: 1) * polovina1 + (polovina2 == s? 2: 1) * polovina2);
        }
        lista1.push_back(temp1);
        lista2.push_back(temp2);

        listaS.push_back(vratiNajveciPodniz(lista2[i]));
        listaMax1.push_back(vratiNajveciPodniz(lista1[i]));
        listaMax2.push_back(listaMax1[i]);
        listaRazlike.push_back(listaS[i] - listaMax1[i]);
    }
    int max1index = vratiIndexMaxElementaSaPrioritetom(listaS, listaRazlike);
    int max2index = vratiIndexMaxElementaSaPrioritetom(listaRazlike, listaS);
    int rjesenje1 = listaS[max1index];
    int rjesenje2 = listaS[max2index];
    listaMax1.erase(listaMax1.begin() + max1index);
    listaMax2.erase(listaMax2.begin() + max2index);

    for (int i = 1; i < p; i++) {
        int index1 = vratiIndexMaxElementa(listaMax1);
        rjesenje1 += listaMax1[index1];
        listaMax1.erase(listaMax1.begin() + index1);

        int index2 = vratiIndexMaxElementa(listaMax2);
        rjesenje2 += listaMax2[index2];
        listaMax2.erase(listaMax2.begin() + index2);
    }
    return rjesenje1 > rjesenje2 ? rjesenje1 : rjesenje2;
}

int MaxUcinak(int n, int k, int p, int s, int* poeni) {
    vector<vector<int> > lista;
    for(int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = i * k; j < (i + 1) * k; j++) {
            temp.push_back(poeni[j]);
        }
        lista.push_back(temp);
    }
    return vratiMaxBodove(n, k, p, s, lista);
}
