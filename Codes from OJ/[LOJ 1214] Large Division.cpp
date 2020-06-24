/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int tc, i, j, k, b, len;
    long long sum, ten;
    char str[205];
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> str >> b;
 
        len = strlen(str);
        ten = 1;
        sum = (str[len-1]-'0') % b;
        for(j=len-2; j>=0; j--) {
            if(str[j]>='0' && str[j]<='9') {
                ten *= 10;
                ten %= b;
                sum += ten*(str[j]-'0');
                sum %= b;
            }
        }
        if(sum==0) printf("Case %d: divisible\n", i+1);
        else printf("Case %d: not divisible\n", i+1);
    }
 
    return 0;
}
