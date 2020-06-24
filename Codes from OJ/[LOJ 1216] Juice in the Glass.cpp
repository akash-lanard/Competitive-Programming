/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1.0)

int main()
{
    int tc, i, j;
    double  r1, r2, r, h, p, x, ans, vol1, vol2;

    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> r1 >> r2 >> h >> p;

        x = r2*h / (r1-r2);

        r = (r2*(p+x)) / x;

        vol1 = (PI*r*r*(p+x)) / 3.0;
        vol2 = (PI*r2*r2*x) / 3.0;
        printf("Case %d: %0.10lf\n", i+1, vol1-vol2);
    }

    return 0;
}
