/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int tc, i, j, k, n, p, q, cnt, sum;
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> n >> p >> q;
        int ara[n];
        for(j=0; j<n; j++) {
            cin >> ara[j];
        }
        sort(ara, ara+n);
        cnt = 0;
        sum = 0;
        for(j=0; j<n; j++) {
            if(cnt+1>p || sum+ara[j]>q) break;
            cnt++;
            sum+=ara[j];
        }
        printf("Case %d: %d\n", i+1, cnt);
    }
 
    return 0;
}
