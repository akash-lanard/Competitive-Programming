/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
#define PI 2*acos(0.0)
int main()
{
    int tc, i, j;
    double r, ans;
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> r;
        ans = (4*r*r) - (PI*r*r);
 
        printf("Case %d: %0.2lf\n", i+1, ans);
    }
 
    return 0;
}
