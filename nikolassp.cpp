    #include <iostream>
    #include <cstdio>
    #include <cmath>
    #include <algorithm>
    #include <vector>
    #include <set>

    using namespace std;

    set < int> primes, sqr_prime_ok;
    vector < int> prosti;
    bool iscomp[200002];

    int a, b, k, n, cnt;
    int dp[200001];

    void izvuci_proste( int upper_bound){

        for( int i=2; i<= upper_bound; ++i)

            if( !iscomp[i]){

             for( int j=2; i*j<= upper_bound; ++j)
                if( !iscomp[i*j]) iscomp[i*j]= true;

              prosti.push_back(i*i);
              primes.insert(i*i);
            }
    }

    int main()
    {
        scanf("%d%d%d", &a, &b, &k);

        izvuci_proste(b+5);
        n= prosti.size();


        dp[0]= 1;

        for( int i=0; i<n; ++i)

            for( int j= prosti[i]; j<=b; ++j){

                 if( dp[j-prosti[i]] && (dp[j-prosti[i]] + 1 < dp[j] || !dp[j] )){

                     dp[j]= dp[j-prosti[i]] + 1;

                     if( primes.find(j) != primes.end() && j >= a)
                        if( dp[j]-1 <= k && dp[j]>2 ) sqr_prime_ok.insert(j);
                }
            }

        for( int i=a; i<=b; ++i)
            if( sqr_prime_ok.find(i) != sqr_prime_ok.end() || (dp[i]>2 && dp[i]-1<=k) ) cnt++;
        printf("%d\n", cnt);

        return 0;
    }

