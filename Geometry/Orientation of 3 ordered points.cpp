#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};
// To find orientation of ordered triplet (p1, p2, p3).
// The function returns following values
// 0 --> p, q, r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p1, Point p2, Point p3)
{
    int val = (p2.y - p1.y) * (p3.x - p2.x) -
                (p2.x - p1.x) * (p3.y - p2.y);

    if(val==0) return 0; //colinear
    return (val>0)? 1:2; //clock or counterclock wise
}

int main()
{
    Point p1 = {0, 0}, p2 = {4, 4}, p3 = {1, 7};
    int o = orientation(p1, p2, p3);
    if(o==0) cout << "Linear\n";
    else if(o==1) cout << "Clockwise\n";
    else cout << "CounterClockwise\n";
    return 0;
}
