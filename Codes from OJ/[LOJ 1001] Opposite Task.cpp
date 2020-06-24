/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc, n, i, j;

    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> n;
        if(n<=10) printf("0 %d\n", n);
        else printf("10 %d\n", n-10);
    }

    return 0;
}
