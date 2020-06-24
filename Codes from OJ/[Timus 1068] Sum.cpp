/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, i, sum=0;
 
    cin >> n;
 
    if(n==1) sum = 1;
    else if(n>1) {
        for(i=1; i<=n; i++) {
            sum += i;
        }
    }
    else if(n<1) {
        for(i=1; i>=n; i--) {
            sum += i;
        }
    }
 
    cout << sum;
 
    return 0;
}
