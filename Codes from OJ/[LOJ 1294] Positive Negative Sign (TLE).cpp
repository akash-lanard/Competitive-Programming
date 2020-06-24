/// Verdict: TLE
/// Brute-force won't work. There is a pattern

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long tc;

    scanf("%lld", &tc);
    for(int i=0; i<tc; i++) {
        long long n, m, sum, x;
        scanf("%lld %lld", &n, &m);
        sum = 0;
        for(int j=1; j<=n; j++) {
            if(((j-1)/m)%2) sum+=j;
            else sum-=j;
        }
        printf("Case %d: %lld\n", i+1, sum);
    }

    return 0;
}
