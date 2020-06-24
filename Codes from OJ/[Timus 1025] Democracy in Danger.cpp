/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, ara[101], k, ans;

    cin >> k;
    for(i=0; i<k; i++) {
        cin >> ara[i];
    }

    sort(ara, ara+k);
    ans = 0;
    for(i=0; i<=k/2; i++) {
        ans += ara[i]/2 + 1;
    }

    cout << ans;

    return 0;
}
