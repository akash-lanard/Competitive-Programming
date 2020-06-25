/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF) {
        int init = 1;
        int ans = 0;

        int temp = n;
        while(1) {
            if(init) {
                ans += temp;
                temp += 2;
                init = 0;
            }
            else {
                ans += (temp/3);
                temp = (temp/3) + (temp%3);
            }
            if(temp<3) break;
        }
        if(temp==1) {
            init = 1;
            ans = 0;
            temp = n;
            while(1) {
                if(init) {
                    ans += temp;
                    temp += 1;
                    init = 0;
                }
                else {
                    ans += (temp/3);
                    temp = (temp/3) + (temp%3);
                }
                if(temp<3) break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
