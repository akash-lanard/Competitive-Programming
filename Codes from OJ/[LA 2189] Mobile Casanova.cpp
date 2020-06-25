/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int nod(int n)
{
    if(n==0) return 1;
    int ret = 0;
    while(n>0) {
        n /= 10;
        ret++;
    }
    return ret;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for(int k=0; ;k++) {
        int n;
        scanf("%d", &n);
        if(n==0) break;
        int ff = 0;
        int prev = 0;
        int cnt = 0;
        printf("Case %d:\n", k+1);
        for(int i=0; i<n; i++) {
            string str;
            cin >> str;
            int num;
            string str2 = str.substr(1, str.size()-1);
            stringstream is(str2);
            while(is >> num) {

            }
            if(ff==0) {
                ff = num;
                prev = num;
                cnt = 0;
            }
            else {
                if(num==prev+1) {
                    prev = num;
                    cnt++;
                }
                else {
                    if(ff==prev) {
                        cout << 0 << ff << endl;
                        ff = num;
                        prev = num;
                        cnt = 0;
                    }
                    else {
                        int temp1 = ff;
                        int temp2 = prev;
                        int m = 1;
                        while(temp1!=temp2) {
                            temp1 /= 10;
                            temp2 /= 10;
                            m *= 10;
                        }
                        int r1 = ff%m;
                        int r2 = prev%m;
                        string ss = "";
                        if(nod(r1)<nod(m)-1) {
                            for(int j=nod(r1); j<nod(m)-1; j++) {
                                ss += '0';
                            }
                        }
                        if(temp1==0) cout << 0 << ss << r1 << '-' << r2 << endl;
                        else cout << 0 << temp1 << ss << r1 << '-' << r2 << endl;
                        ff = num;
                        prev = num;
                        cnt = 0;
                    }
                }
            }
        }
        if(ff==prev) {
            cout << 0 << ff << endl;
        }
        else {
            int temp1 = ff;
            int temp2 = prev;
            int m = 1;
            while(temp1!=temp2) {
                temp1 /= 10;
                temp2 /= 10;
                m *= 10;
            }
            int r1 = ff%m;
            int r2 = prev%m;
            string ss = "";
            if(nod(r1)<nod(m)-1) {
                for(int j=nod(r1); j<nod(m)-1; j++) {
                    ss += '0';
                }
            }
            if(temp1==0) cout << 0 << ss << r1 << '-' << r2 << endl;
            else cout << 0 << temp1 << ss << r1 << '-' << r2 << endl;
        }
        printf("\n");
    }
    return 0;
}
