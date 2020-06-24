/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long tc;

    scanf("%lld", &tc);
    for(int i=0; i<tc; i++) {
        long long n, m;
        scanf("%lld %lld", &n, &m);
        printf("Case %d: %lld\n", i+1, (m*n)/2);
    }

    return 0;
}
