/// Verdict: AC

#include <iostream>
using namespace std;

int main()
{
    int tc, i, j, x, y, a, b;

    cin >> tc;
    while(tc!=0) {
        cin >> x >> y;
        for(i=0; i<tc; i++) {
            cin >> a >> b;
            if(a>x && b>y) cout << "NE\n";
            else if(a<x && b>y) cout << "NO\n";
            else if(a<x && b<y) cout << "SO\n";
            else if(a>x && b<y) cout << "SE\n";
            else cout << "divisa\n";
        }
        cin >> tc;
    }

    return 0;
}
