/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
#define PI acos(-1.0)
 
int main()
{
    int tc, i;
    double R, n, r;
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> R >> n;
 
        r = (R*sin(PI/n)) / (1+sin(PI/n));
 
        printf("Case %d: %0.10lf\n", i+1, r);
    }
 
    return 0;
}
