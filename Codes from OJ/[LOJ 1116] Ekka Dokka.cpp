/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    long long tc, w, m, i, j;
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> w;
        m = 1;
        while(w%2==0) {
            m *= 2;
            w /= 2;
        }
 
        if(m==1) printf("Case %lld: Impossible\n", i+1);
        else printf("Case %lld: %lld %lld\n", i+1, w, m);
    }
 
    return 0;
}
