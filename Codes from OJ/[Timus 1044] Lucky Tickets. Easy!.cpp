/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
//generated the array first using brute force
//10, 670, 55252, 4816030
int main()
{
    int n, ans[4] = {10, 670, 55252, 4816030};

    cin >> n;

    if(n==2) cout << ans[0];
    else if(n==4) cout << ans[1];
    else if(n==6) cout << ans[2];
    else if(n==8) cout << ans[3];

    return 0;
}
