/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int tc, n, par, i, j;
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> n;
        par = 0;
        for(j=0; (n>>j)>0; j++) {
            if((n>>j)&1 == 1) par++;
        }
 
        if(par%2==0) printf("Case %d: even\n", i+1);
        else printf("Case %d: odd\n", i+1);
    }
 
    return 0;
}
