/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc, i, j, k;
    double v1, v2, v3, a1, a2, s1, s2, t1, t2;

    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> v1 >> v2 >> v3 >> a1 >> a2;

        t1 = v1/a1;
        t2 = v2/a2;
        s1 = v1*t1 - (0.5*a1*t1*t1);
        s2 = v2*t2 - (0.5*a2*t2*t2);

        printf("Case %d: %0.8lf %0.8lf\n", i+1, s1+s2, v3*(max(t1, t2)));
    }

    return 0;
}
