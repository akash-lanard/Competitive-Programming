/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int tc, n, i, j, k, x, y, z;
    pair<int, string> p[100];
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> n;
        for(j=0; j<n; j++) {
            cin >> p[j].second;
            cin >> x >> y >> z;
            p[j].first = x*y*z;
        }
        sort(p, p+n);
        if(p[0].first==p[n-1].first) {
            cout << "Case " << i+1 << ": " << "no thief" << endl;
        }
        else {
            cout << "Case " << i+1 << ": " << p[n-1].second << " took chocolate from " << p[0].second << endl;
        }
    }
    return 0;
}
