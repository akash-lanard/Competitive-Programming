/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int tc, A, B, cntA, cntB, i, j;
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> A >> B;
 
        cntA = ((A-1)/3)*2;
        if((A-1)%3==2) cntA++;
 
        cntB = (B/3)*2;
        if(B%3==2) cntB++;
 
        printf("Case %d: %d\n", i+1, cntB-cntA);
    }
 
    return 0;
}
