/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
#define PI acos(-1.0)
int main()
{
    int tc, i, j, k;
    double ox, oy, ax, ay, bx, by, OA, OB, AB, coso, aob, frac, total;
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> ox >> oy >> ax >> ay >> bx >> by;
        OA = sqrt(pow(ox-ax, 2) + pow(oy-ay, 2));
        OB = sqrt(pow(ox-bx, 2) + pow(oy-by, 2));
        AB = sqrt(pow(ax-bx, 2) + pow(ay-by, 2));
 
        //printf("OA = %lf, OB = %lf, AB = %lf\n", OA, OB, AB);
 
        coso = (pow(OA, 2.0) + pow(OB, 2.0) - pow(AB, 2.0)) / (2.0*OA*OB);
        //printf("coso = %lf\n", coso);
        aob = acos(coso);
        aob = (aob*180)/PI;
        //printf("aob = %lf\n", aob);
 
        frac = aob/360.0;
 
        total = 2*PI*OA*frac;
 
        printf("Case %d: %0.8lf\n", i+1, total);
    }
 
    return 0;
}
