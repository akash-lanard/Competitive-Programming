/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int tc, N, M, K, i, j, k, l, p;
 
    cin >> tc;
    for(i=0; i<tc; i++) {
        cin >> N >> M >> K;
        int ara[N][K];
        for(j=0; j<N; j++) {
            for(k=0; k<K; k++) {
                cin >> ara[j][k];
            }
        }
        cin >> p;
        int sol[p];
        for(j=0; j<p; j++) {
            cin >> sol[j];
        }
        vector<int> v(sol, sol+p);
        sort(v.begin(), v.end());
        int isSat[N];
        memset(isSat, 0, sizeof(isSat));
 
        /*for(j=0; j<N; j++) {
            for(k=0; k<K; k++) {
                printf("ara[%d][%d] = %d\n", j, k, ara[j][k])
            }
        }*/
        for(j=0; j<N; j++) {
            for(k=0; k<K; k++) {
                if(ara[j][k]>0) {
                    if(binary_search(v.begin(), v.end(), ara[j][k])) {
                        isSat[j] = 1;
                        //cout << "I'm here\n";
                        break;
                    }
                }
                else if(ara[j][k]<0) {
                    if(!binary_search(v.begin(), v.end(), -1*ara[j][k])) {
                        isSat[j] = 1;
                        //cout << "I'm here\n";
                        break;
                    }
                }
            }
        }
 
        int flag = 1;
        for(j=0; j<N; j++) {
            if(isSat[j]==0) {
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
