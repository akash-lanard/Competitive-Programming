/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int tc, n, i, j, num, sum;
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> n;
        sum = 0;
        for(j=0; j<n; j++) {
            cin >> num;
            if(num>0) sum+=num;
        }
        printf("Case %d: %d\n", i+1, sum);
    }
 
    return 0;
}
