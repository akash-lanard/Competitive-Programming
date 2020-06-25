/// Verdict: AC

#include <iostream>
using namespace std;

int main()
{
    int tc, i, j, n, m, ans;

    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> n >> m;
        ans = (n/3) * (m/3);
        cout << ans << "\n";
    }

    return 0;
}
