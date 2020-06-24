/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int tc, i, j, k, cnt1[26], cnt2[26], flag;
    string s1, s2;
 
    cin >> tc;
    getline(cin, s1);
    for(i=0; i<tc; i++) {
        getline(cin, s1);
        getline(cin, s2);
 
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        for(string::iterator it = s1.begin(); it!=s1.end(); ++it) {
            if(*it>='a' && *it<='z') cnt1[*it-'a']++;
            else if(*it>='A' && *it<='Z') cnt1[*it-'A']++;
        }
 
        for(string::iterator it = s2.begin(); it!=s2.end(); ++it) {
            if(*it>='a' && *it<='z') cnt2[*it-'a']++;
            else if(*it>='A' && *it<='Z') cnt2[*it-'A']++;
        }
 
        flag = 1;
        for(j=0; j<26; j++) {
            if(cnt1[j]!=cnt2[j]) {
                flag = 0;
                break;
            }
        }
 
        if(flag) {
            printf("Case %d: Yes\n", i+1);
        }
        else {
            printf("Case %d: No\n", i+1);
        }
    }
    return 0;
}
