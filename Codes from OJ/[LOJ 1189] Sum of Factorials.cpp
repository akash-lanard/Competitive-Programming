/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
long long ara[21];
 
void factGen()
{
    ara[0] = 1;
    long long f = 1;
    for(long long i=1; i<=20; i++) {
        f *= i;
        ara[i] = f;
    }
}
 
void f(long long n, long long tc)
{
    long long arafact[21], i, j;
    for(i=20, j=0; i>=0; i--) {
        if(ara[i]<=n) {
            n -= ara[i];
            arafact[j] = i;
            j++;
        }
    }
    if(n>0) {
        printf("Case %lld: impossible\n", tc+1);
    }
    else {
        printf("Case %lld: ", tc+1);
        for(long long i=j-1; i>=0; i--) {
            if(i==j-1) printf("%lld!", arafact[i]);
            else printf("+%lld!", arafact[i]);
        }
        printf("\n");
    }
}
 
int main()
{
    long long tc, i, j, n;
    factGen();
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> n;
        f(n, i);
    }
 
    return 0;
}
