/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int tc, mypos, liftpos, i, j;
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> mypos >> liftpos;
 
        printf("Case %d: %d\n", i+1, 4*(abs(mypos-liftpos)+mypos) + 19);
    }
 
    return 0;
}
