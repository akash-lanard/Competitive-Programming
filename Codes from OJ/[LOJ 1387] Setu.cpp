/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int tc, n, i, j, k, sum, x;
    string str;
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> n;
        printf("Case %d:\n", i+1);
        sum = 0;
        for(j=0; j<n; j++) {
            cin >> str;
            if(str=="donate") {
                cin >> x;
                sum += x;
            }
            else if(str=="report") {
                cout << sum << endl;
            }
        }
    }
    return 0;
}
