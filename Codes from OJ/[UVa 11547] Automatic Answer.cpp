/// Verdict: AC

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int tc, i, j, n, x, y;

    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> n;

        x = 315*n + 36962;
        y = (x/10) % 10;
        cout << abs(y) << "\n";
    }

    return 0;
}
