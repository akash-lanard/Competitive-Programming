/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int ara[30];

int recur(int cur, int sz, int sum1, int sum2)
{
    if(cur==sz) return abs(sum1-sum2);

    int a = recur(cur+1, sz, sum1+ara[cur], sum2);
    int b = recur(cur+1, sz, sum1, sum2+ara[cur]);

    return min(a, b);
}

int main()
{
    int n, i, ans;

    cin >> n;
    for(i=0; i<n; i++) {
        cin >> ara[i];
    }
    ans = recur(0, n, 0, 0);
    cout << ans << endl;
    return 0;
}
