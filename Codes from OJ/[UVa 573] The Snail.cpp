/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

int main()
{
    while(1) {
        double H, U, D, F;
        scanf("%lf %lf %lf %lf", &H, &U, &D, &F);
        if(H==0.0) break;
        double dis = 0.0;
        double rate = U*(F/100.0);
        int i;
        int flag = 1;
        for(i=1; ; i++) {
            dis += U;
            if(dis>H) break;
            U -= rate;
            if(U<=0.0) U = 0.0;
            dis -= D;
            if(dis<0.0) {
                flag = 0;
                break;
            }
        }
        if(flag) printf("success on day %d\n", i);
        else printf("failure on day %d\n", i);
    }
    return 0;
}
