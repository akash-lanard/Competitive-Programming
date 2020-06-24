/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
#define PI 2*acos(0.0)
 
int main()
{
    int tc, i, j, k;
    double r1, r2, r3, s, triangle_area, a, b, c, angleC, angleB, angleA, areaA, areaB, areaC, ans, xC, xA, xB;
    double angleAd, angleBd, angleCd;
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> r1 >> r2 >> r3;
 
        s = r1+r2+r3;
 
        a = r2 + r3;
        b = r1 + r3;
        c = r1 + r2;
 
        triangle_area = sqrt(s*(s-a)*(s-b)*(s-c));
 
        xC = ((a*a)+(b*b)-(c*c)) / (2*a*b);
        angleC = acos(xC);
        angleCd = (angleC * 180) / (PI);
        //printf("PI = %lf\n", PI);
        //printf("angleC = %lf\n", angleC);
        //printf("angleCd = %lf\n", angleCd);
 
        xA = ((b*b)+(c*c)-(a*a)) / (2*b*c);
        angleA = acos(xA);
        angleAd = (angleA * 180) / (PI);
 
        xB = ((a*a)+(c*c)-(b*b)) / (2*a*c);
        angleB = acos(xB);
        angleBd = (angleB * 180) / (PI);
 
        areaA = ((PI*r1*r1)*angleAd) / 360;
        areaB = ((PI*r2*r2)*angleBd) / 360;
        areaC = ((PI*r3*r3)*angleCd) / 360;
 
        ans = triangle_area - (areaA + areaB + areaC);
 
        /*printf("\ns = %0.2lf, a = %0.2lf, b = %0.2lf, c = %0.2lf\n", s, a, b, c);
        printf("triangle_area = %0.2lf\n", triangle_area);
        printf("xC = %0.2lf, xA = %0.2lf, xC = %0.2lf\n", xC, xA, xB);
        printf("angleC = %0.2lf, angleA = %0.2lf, angleB = %0.2lf\n", angleC, angleA, angleB);
        printf("angleCd = %0.2lf, angleAd = %0.2lf, angleBd = %0.2lf\n", angleCd, angleAd, angleBd);
        printf("areaA = %0.2lf, areaB = %0.2lf, areaC = %0.2lf\n", areaA, areaB, areaC);
        printf("ans = %0.2lf\n\n", ans);*/
 
        printf("Case %d: %0.10lf\n", i+1, ans);
    }
 
    return 0;
}
