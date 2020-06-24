/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int tc, i, j, k, r1, c1, r2, c2, x, y, z;
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        if(((r1+c1)%2) != ((r2+c2)%2)) {
            printf("Case %d: impossible\n", i+1);
        }
        else {
            x = abs(r1-r2);
            y = abs(c1-c2);
            if(x==y) {
                printf("Case %d: 1\n", i+1);
            }
            else {
                printf("Case %d: 2\n", i+1);
            }
        }
    }
 
    return 0;
}
