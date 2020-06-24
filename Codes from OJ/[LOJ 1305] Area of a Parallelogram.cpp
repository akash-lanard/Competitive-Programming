/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int tc, i, j;
    double ax, ay, bx, by, cx, cy, dx, dy, area, ox, oy, ex, ey, dia1, dia2;
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> ax >> ay >> bx >> by >> cx >> cy;
 
        dx = ax + cx - bx;
        dy = ay + cy - by;
 
        area = abs((ax*by + bx*cy + cx*dy + dx*ay) - (ay*bx + by*cx + cy*dx + dy*ax)) / 2.0;
        //cout << "Case " << i+1 << ": " << dx << ' ' << dy << ' ' << area << '\n';
        printf("Case %d: %d %d %d\n", i+1, (int)dx, (int)dy, (int)area);
    }
 
    return 0;
}
