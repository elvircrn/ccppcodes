#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#define MAX 90099
using namespace std;
char str[MAX]; //input
int Rank[MAX], suffixArray[MAX]; //output
int cnt[MAX], Next[MAX]; //internal
bool bh[MAX], b2h[MAX];
int Height[MAX];
int AccumulatedCount[MAX];

bool smaller_first_char(int a, int b)
{
	return str[a] < str[b];
}
void print(int index)
{
	for(int i=index;i<strlen(str);++i)
	{
		cout<<str[i];
	}
	cout<<endl;
}

void suffixSort(int n){
	for (int i=0; i<n; ++i){
		suffixArray[i] = i;
	}
	sort(suffixArray, suffixArray + n, smaller_first_char);

	for (int i=0; i<n; ++i){
		bh[i] = i == 0 || str[suffixArray[i]] != str[suffixArray[i-1]];
		b2h[i] = false;
	}

	for (int h = 1; h < n; h <<= 1){
		int buckets = 0;
		for (int i=0, j; i < n; i = j){
			j = i + 1;
			while (j < n && !bh[j]) j++;
			Next[i] = j;
			buckets++;
		}
		if (buckets == n) break;

		for (int i = 0; i < n; i = Next[i]){
			cnt[i] = 0;
			for (int j = i; j < Next[i]; ++j){
				Rank[suffixArray[j]] = i;
			}
		}

		cnt[Rank[n - h]]++;
		b2h[Rank[n - h]] = true;
		for (int i = 0; i < n; i = Next[i]){
			for (int j = i; j < Next[i]; ++j){
				int s = suffixArray[j] - h;
				if (s >= 0){
					int head = Rank[s];
					Rank[s] = head + cnt[head]++;
					b2h[Rank[s]] = true;
				}
			}
			for (int j = i; j < Next[i]; ++j){
				int s = suffixArray[j] - h;
				if (s >= 0 && b2h[Rank[s]]){
					for (int k = Rank[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
				}
			}
		}
		for (int i=0; i<n; ++i){
			suffixArray[Rank[i]] = i;
			bh[i] |= b2h[i];
		}
	}
	for (int i=0; i<n; ++i)
	{
		Rank[suffixArray[i]] = i;
	}
}

void getHeight(int n)
{
	for (int i=0; i<n; ++i) Rank[suffixArray[i]] = i;
	Height[0] = 0;
	for (int i=0, h=0; i<n; ++i)
	{
		if (Rank[i] > 0)
		{
			int j = suffixArray[Rank[i]-1];
			while (i + h < n && j + h < n && str[i+h] == str[j+h])
			{
				h++;
			}
			Height[Rank[i]] = h;
			if (h > 0) h--;
		}
	}
}

int main()
{
	int kth,T, diff,suffixsize;
	gets(str);
	int Len=strlen(str);
	scanf("%d",&T);
	suffixSort(Len);
	getHeight(Len);

	int sum=0;
	for(int i=0;i<Len;++i)
	{
		suffixsize=(Len-suffixArray[i]);
		diff=suffixsize-Height[i];					/*Note that the diff is the total distinct substrings that a suffix i will  give*/
		sum=sum+diff;
		AccumulatedCount[i]=sum;
	}

	while(T--)
	{
		scanf("%d",&kth);
		int FirstEntry=0;
		for(int i=0;i<Len;++i)
		{
			if(AccumulatedCount[i]>=kth)
			{
				FirstEntry=i;
				break;
			}
		}

		int sharedprefixLength=Height[FirstEntry];
		int Idx,j;
		for(Idx=suffixArray[FirstEntry],j=0;j<sharedprefixLength;++j,++Idx)
			putc(str[Idx],stdout);

		for(int j=0;j<kth-AccumulatedCount[FirstEntry-1];++j,++Idx)
			putc(str[Idx],stdout);

		putc('\n',stdout);
	}
	return 0;
}
/*
odg, lektira, pismena,
*/

