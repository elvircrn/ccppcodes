#include <cstdio>
#include <climits>
#include <cstring>

using namespace std;

const unsigned int Kante_n = 3;
typedef unsigned int Kante[Kante_n];

Kante kante_kap;
unsigned int kante_suma;

unsigned int kante_moguce[16777216];

inline void bitNizPostavi(unsigned int* bit_niz, unsigned int i, bool vrijednost)
{
	bit_niz[i/32] &= ~(1<<(i%32));
	bit_niz[i/32] |= 1<<(i%32);
}

inline bool bitNizProvjeri(unsigned int* bit_niz, unsigned int i)
{
	return bit_niz[i/32] & (1<<(i%32));
}

unsigned int kodiraj(Kante kante)
{
	unsigned int kante_pune_flag = 0;
	unsigned int kante_unutrasnje_vrijednost = 0;
	unsigned int kante_unutrasnje_flag = 0;
	for (unsigned int i = 0; i < Kante_n; ++i)
	{
		if (kante[i] != 0 && kante[i]!=kante_kap[i])
		{
			kante_unutrasnje_flag |= 1 << i;
			kante_unutrasnje_vrijednost = kante[i];
		}
		else
		{
			kante_pune_flag <<= 1;
			kante_pune_flag |= (kante[i]==kante_kap[i]);
		}
	}
	if (kante_unutrasnje_flag == 0)
		kante_pune_flag >>= 1;
	return (kante_pune_flag << 27) | (kante_unutrasnje_flag << 24) | kante_unutrasnje_vrijednost;
}

void dekodiraj(unsigned int kodirano, Kante kante)
{
	unsigned int kante_pune_flag = kodirano >> 27;
	unsigned int kante_unutrasnje_vrijednost = kodirano & 0xFFFFFF;
	unsigned int kante_unutrasnje_flag = (kodirano >> 24) & 0x7;
	//fprintf(stderr, "DEBUG %u %u %u", kante_pune_flag, kante_unutrasnje_vrijednost, kante_unutrasnje_flag);
	kante[0] = kante[1] = kante[2] = 0;
	if (kante_unutrasnje_flag == 0x1)
	{
		kante[0] = kante_unutrasnje_vrijednost;
		if (kante_pune_flag & 0x1)
			kante[2] = kante_kap[2];
		if (kante_pune_flag & 0x2)
			kante[1] = kante_kap[1];
	}
	else if (kante_unutrasnje_flag == 0x2)
	{
		kante[1] = kante_unutrasnje_vrijednost;
		if (kante_pune_flag & 0x1)
			kante[2] = kante_kap[2];
		if (kante_pune_flag & 0x2)
			kante[0] = kante_kap[0];
	}
	else if (kante_unutrasnje_flag == 0x4)
	{
		kante[2] = kante_unutrasnje_vrijednost;
		if (kante_pune_flag & 0x1)
			kante[1] = kante_kap[1];
		if (kante_pune_flag & 0x2)
			kante[0] = kante_kap[0];
	}
	else if (kante_unutrasnje_flag == 0x3)
	{
		kante[1] = kante_unutrasnje_vrijednost;
		if (kante_pune_flag)
			kante[2] = kante_kap[2];
		kante[0] = kante_suma - kante[1] - kante[2];
	}
	else if (kante_unutrasnje_flag == 0x5)
	{
		kante[2] = kante_unutrasnje_vrijednost;
		if (kante_pune_flag)
			kante[1] = kante_kap[1];
		kante[0] = kante_suma - kante[1] - kante[2];
	}
	else if (kante_unutrasnje_flag == 0x6)
	{
		kante[2] = kante_unutrasnje_vrijednost;
		if (kante_pune_flag)
			kante[0] = kante_kap[0];
		kante[0] = kante_suma - kante[1] - kante[2];
	}
	else
	{
		if (kante_pune_flag & 0x1)
			kante[1] = kante_kap[1];
		if (kante_pune_flag & 0x2)
			kante[0] = kante_kap[0];
		kante[2] = kante_suma - kante[1] - kante[0];
	}
}

void kanteKopiraj(const Kante iz, Kante u)
{
	for (int i = 0; i < Kante_n; ++i)
		u[i] = iz[i];
}

int kantePrespi(Kante kante, unsigned int iz, unsigned int u, unsigned int maksimalno = UINT_MAX)
{
	unsigned int ostalo_kap = kante_kap[u]-kante[u];
	unsigned int presipa_se = (kante[iz] > maksimalno ? maksimalno : kante[iz]);
	if (presipa_se > ostalo_kap)
	{
		kante[u] = kante_kap[u];
		kante[iz] -=  ostalo_kap;
		return ostalo_kap;
	}
	else
	{
		kante[u] += presipa_se;
		kante[iz] -= presipa_se;
		return presipa_se;
	}
}

unsigned int dfs_cnt = 0;

void dfs(Kante kante)
{
	unsigned int kante_kodirano;
	kante_kodirano = kodiraj(kante);
	if (bitNizProvjeri(kante_moguce, kante_kodirano))
		return;
	//fprintf(stderr, "%d %d %d: %d\n", kante[0], kante[1], kante[2], kante_kodirano);
	dfs_cnt++;
	bitNizPostavi(kante_moguce, kante_kodirano, true);
	for (int i = 0; i < Kante_n; i++)
		if (kante[i] != 0)
			for (int j = (i+1)%Kante_n; j != i; j=(j+1)%Kante_n)
			{
				unsigned int presuto = kantePrespi(kante, i, j);
				dfs(kante);
				kantePrespi(kante, j, i, presuto);
			}
}

bool valid(Kante kante)
{
	if (kante[0] + kante[1] + kante[2] != kante_suma)
		return false;
	int unutrasnje;
	for (int i = 0; i < Kante_n; ++i)
		if (kante[i] > kante_kap[i])
			return false;
		else if (kante[i] != 0 && kante[i] != kante_kap[i])
			++unutrasnje;
	return unutrasnje != 3;
}

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	scanf("%u %u %u", kante_kap, kante_kap+1, kante_kap+2);
	Kante kante;
	scanf("%u %u %u", kante, kante+1, kante+2);
	kante_suma = kante[0] + kante[1] + kante[2];
	memset(kante_moguce, 0, sizeof(kante_moguce));
	dfs(kante);
	//printf("%u\n", dfs_cnt);
	int n;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%u %u %u", kante, kante+1, kante+2);
		if (valid(kante) && bitNizProvjeri(kante_moguce, kodiraj(kante)))
			printf("DA\n");
		else
			printf("NE\n");
	}
	fclose(stdin);

	return 0;
}

