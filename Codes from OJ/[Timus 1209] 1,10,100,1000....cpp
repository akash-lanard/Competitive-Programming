/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, k, i, j, m;
 
    cin >> n;
    for(i=0; i<n; i++) {
        cin >> k;
        m = k;
        for(j=1; m>j; j++) {
            m -= j;
        }
        if(i==0) {
            if(m==1) printf("1");
            else printf("0");
        }
        else {
            if(m==1) printf(" 1");
            else printf(" 0");
        }
    }
 
    return 0;
}
