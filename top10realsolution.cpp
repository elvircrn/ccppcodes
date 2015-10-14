// 2.3 secs
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i=0,_n=n; i<_n; i++)

#define MAXN 200001

int RA[MAXN], SA[MAXN], LCP[MAXN], *FC, *SC, step;
int V[MAXN], L[MAXN], I[MAXN], SAP[MAXN], N,Q;
char S[MAXN], taken[MAXN];

bool cmp(int a, int b){
	if (step==-1 || FC[a]!=FC[b]) return FC[a] < FC[b];
	return FC[a+(1<<step)] < FC[b+(1<<step)];
}

bool better(int a, int b){
	if (a==b) return false; else a = V[a], b = V[b];
	if (L[a]!=L[b]) return L[a] < L[b];
	if (SAP[a]!=SAP[b]) return SAP[a] < SAP[b];
	return a < b;
}

void add(vector<int> &v, int x){
	if (v.size()==0){ v.push_back(x); return; }
	REP(i,v.size()) if (v[i]==x) return;
	v.push_back(x);
	for (int i=v.size()-1; i>0; i--)
		if (better(v[i],v[i-1])) swap(v[i],v[i-1]);
	if (v.size()>10) v.pop_back();
}

void addAll(vector<int> &t, vector<int> &s){
	REP(i,s.size()) add(t,s[i]);
}

struct Node {
	vector<int> top10;
	int L,R;
};

Node nodes[MAXN*2];
int nn = 0;

int build(int L, int R){
	int idx = nn++;
	nodes[idx].top10.clear();
	nodes[idx].L = nodes[idx].R = -1;
	if (L==R){
		add(nodes[idx].top10, I[SA[L]]);
	} else {
		int M = (L+R)/2;
		nodes[idx].L = build(L,M);
		nodes[idx].R = build(M+1,R);
		addAll(nodes[idx].top10, nodes[nodes[idx].L].top10);
		addAll(nodes[idx].top10, nodes[nodes[idx].R].top10);
	}
	return idx;
}

void top10(int idx, int L, int R, int qL, int qR, vector<int> &res){
	if (R<qL || qR<L) return;
	if (qL <= L && R <= qR){
		if (L==R) add(res, I[SA[L]]);
		else addAll(res, nodes[idx].top10);
	} else {
		int M = (L+R)/2;
		top10(nodes[idx].L, L,M, qL,qR, res);
		top10(nodes[idx].R, M+1,R, qL,qR, res);
	}
}

int main(){
	freopen("top10.in","r",stdin);
	freopen("top10fh.out","w",stdout);
	clock_t st = clock();

	scanf("%d",&N);
	V[0] = 0;
	REP(i,N){
		I[V[i]] = i;
		scanf("%s",S+V[i]);
		L[V[i]] = strlen(S+V[i]);
		V[i+1] = V[i] + L[V[i]] + 1;
		for (int j=V[i]+1; j<V[i+1]; j++)
			I[j] = I[V[i]], L[j] = L[V[i]];
	}
	assert(V[N] < MAXN);

	// construct suffix array
	for (int i=0; i<V[N]; i++) RA[i] = S[SA[i] = i];
	for (FC=RA, SC=LCP, step=-1; (1<<step)<V[N]; step++){
		sort(SA, SA+V[N], cmp);
		int cnt = 0;
		for (int i=0; i<V[N]; i++){
			if (i>0 && cmp(SA[i-1],SA[i])) cnt++;
			SC[SA[i]] = cnt;
		}
		if (cnt==V[N]-1) break;
		swap(FC,SC);
	}
	for (int i=0; i<V[N]; i++) RA[SA[i]] = i;

	// populate SAP to determine which is smaller between S+V[a] and S+V[b] O(N log n)
	REP(i,N){
		int lo=0, hi=V[N];
		while (lo+1<hi){
			int mid = (lo+hi)/2;
			if (strncmp(S+SA[mid],S+V[i],L[V[i]])<=0)
				lo = mid;
			else
				hi = mid;
		}
		SAP[V[i]] = lo;
	}

	int root = build(0,V[N]-1);

	// answer the queries
	scanf("%d",&Q);
	REP(i,Q){
		scanf("%s",S+V[N]);
		char *t = S+V[N];
		int tlen = strlen(t);

		// find the smallest index on suffix array
		int lo=0, hi=V[N];
		while (lo+1<hi){
			int mid = (lo+hi)/2;
			if (strncmp(S+SA[mid],t,tlen)<0)
				lo = mid;
			else
				hi = mid;
		}
		while (lo<V[N] && strncmp(S+SA[lo],t,tlen)<0) lo++;
		int L = lo;

		if (strncmp(S+SA[lo],t,tlen)==0){
			lo=0; hi=V[N];
			while (lo+1<hi){
				int mid = (lo+hi)/2;
				if (strncmp(S+SA[mid],t,tlen)<=0)
					lo = mid;
				else
					hi = mid;
			}
			while (hi==V[N] || strncmp(S+SA[hi],t,tlen)>0) hi--;
			int R = hi;

			vector<int> res;
			top10(root,0,V[N]-1,L,R,res);
			assert(res.size()>0);
			REP(j,res.size()-1) printf("%d ",res[j]+1);
			printf("%d\n",res.back()+1);
		} else {
			puts("-1");
		}
		if (i%10000==0) fprintf(stderr,"%d\n",i);
	}

	fprintf(stderr,"%.3lf\n",1.0*(clock()-st)/CLOCKS_PER_SEC);
}
