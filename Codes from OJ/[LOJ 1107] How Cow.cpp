/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int tc, i, j, k, x1, y1, x2, y2, x[100], y[100], m;
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> m;
        printf("Case %d:\n", i+1);
        for(j=0; j<m; j++) {
            cin >> x[j] >> y[j];
            if(x[j]>x1 && x[j]<x2 && y[j]>y1 && y[j]<y2) {
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
        }
    }
 
    return 0;
}
