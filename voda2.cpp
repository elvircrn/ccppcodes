#include <cstdio>
#include <set>
#include <cstdlib>
#include <iostream>

using namespace std;

const unsigned int Kante_n = 3;

struct Kante
{
	unsigned int k1, k2, k3;
	unsigned int &operator[](unsigned int i)
	{
		if (i == 0)
			return k1;
		else if (i == 1)
			return k2;
		else if (i == 2)
			return k3;
	}
	unsigned int operator[](unsigned int i) const
	{
		if (i == 0)
			return k1;
		else if (i == 1)
			return k2;
		else if (i == 2)
			return k3;
	}
	bool operator<(const Kante& param) const
	{
		if (operator[](0) < param[0])
			return true;
		else if (operator[](0) == param[0])
		{
			if (operator[](1) < param[1])
				return true;
			else if (operator[](1) == param[1])
				return operator[](2)<param[2];
		}
		return false;
	}
};

Kante kante_kap;

set<Kante> kante_moguce;

void kantePrespi(Kante &kante, unsigned int iz, unsigned int u)
{
	unsigned int ostalo_kap = kante_kap[u]-kante[u];
	if (kante[iz] > ostalo_kap)
	{
		kante[u] = kante_kap[u];
		kante[iz] -=  ostalo_kap;
	}
	else
	{
		kante[u] += kante[iz];
		kante[iz] = 0;
	}
}

void dfs(const Kante &kante)
{
	if (kante_moguce.find(kante) != kante_moguce.end())
		return;
	//fprintf(stderr, "%d %d %d\n", kante[0], kante[1], kante[2]);
	kante_moguce.insert(kante);
	for (int i = 0; i < Kante_n; i++)
		if (kante[i] != 0)
			for (int j = (i+1)%Kante_n; j != i; j=(j+1)%Kante_n)
			{
				Kante nova_kante(kante);
				kantePrespi(nova_kante, i, j);
				dfs(nova_kante);
			}
}

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	scanf("%u %u %u", &kante_kap[0], &kante_kap[1], &kante_kap[2]);
	Kante kante;
	scanf("%u %u %u", &kante[0], &kante[1], &kante[2]);
	dfs(kante);
	int n;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%u %u %u", &kante[0], &kante[1], &kante[2]);
		if (kante_moguce.find(kante) != kante_moguce.end())
			printf("DA\n");
		else
			printf("NE\n");
	}
	return 0;
}
