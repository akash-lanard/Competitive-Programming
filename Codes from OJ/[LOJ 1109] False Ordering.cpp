/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
#define SIZE 1000
 
int ara[SIZE+5];
 
int numOfDiv(int n)
{
    int cnt = 0, sq = sqrt(n);
    for(int i=1; i<=sq; i++) {
        if(n%i==0) {
            if(n/i == i) cnt++;
            else cnt+=2;
        }
    }
    return cnt;
}
 
int main()
{
    int tc, n;
 
    for(int i=0; i<=SIZE; i++) {
        ara[i] = i;
    }
 
    for(int i=1; i<SIZE; i++) {
        for(int j=i+1; j<=SIZE; j++) {
            if( ( numOfDiv(ara[j] ) < numOfDiv(ara[i] ) ) ) {
                int temp = ara[j];
                ara[j] = ara[i];
                ara[i] = temp;
            }
            else if( ( ( numOfDiv( ara[j] ) == numOfDiv( ara[i] ) ) && ( ara[j]>ara[i] ) ) ) {
                int temp = ara[j];
                ara[j] = ara[i];
                ara[i] = temp;
            }
        }
    }
 
    cin >> tc;
    for(int i=0; i<tc; i++) {
        cin >> n;
        printf("Case %d: %d\n", i+1, ara[n]);
    }
    //for(int i=1; i<=1000; i++) cout << ara[i] << ' ' << numOfDiv(ara[i]) << endl;
 
    return 0;
}
