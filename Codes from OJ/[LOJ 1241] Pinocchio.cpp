/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc, i, j, cnt, ara[11], n;
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> n;
        cnt = 0;
        for(j=0; j<n; j++) {
            cin >> ara[j];
            if(j==0 && ara[j]>2) {
                cnt += (int)ceil((double)(ara[j]-2)/5.0);
            }
            else if(j!=0 && ara[j]>ara[j-1]) {
                cnt += (int)ceil((double)(ara[j]-ara[j-1])/5.0);
            }
        }
        printf("Case %d: %d\n", i+1, cnt);
    }
    return 0;
}
