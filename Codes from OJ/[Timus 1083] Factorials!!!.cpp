/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, cnt = 0, i, j, k, fact, len;
    char str[25];
 
    cin >> n;
    cin >> str;
 
    len = strlen(str);
 
    //cout << len;
    k = len;
 
    fact = 1;
    for(int i=0;  n-(i*k)>0; i++) {
        fact *= n-(i*k);
        //printf("i= %d, n-(i*k) = %d, fact = %d\n", i, n-(i*k), fact);
    }
 
    cout << fact;
 
    return 0;
}
