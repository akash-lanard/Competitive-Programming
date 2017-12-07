#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);
    for(int i=0; i<tc; i++) {
        int n, d;
        scanf("%d %d", &n, &d);
        int ara_mx[n+5], ara_mn[n+5];
        deque<pair<int, int> > dq_mx, dq_mn;
        for(int j=0; j<n; j++) {
            int x;
            scanf("%d", &x);
            pair<int, int> p;
            p = make_pair(j, x);
            //mx
            if(dq_mx.size()==0 || x<dq_mx.back().second) {
                dq_mx.push_back(p);
            }
            else {
                while(dq_mx.size()!=0 && x>=dq_mx.back().second) {
                    dq_mx.pop_back();
                }
                dq_mx.push_back(p);
            }
            deque<pair<int, int> >::iterator it;
            for(it=dq_mx.begin(); it!=dq_mx.end(); ++it) {
                if(j-dq_mx.front().first>=d) {
                    dq_mx.pop_front();
                }
            }
            ara_mx[j] = dq_mx.front().second;
            //mx

            //mn
            if(dq_mn.size()==0 || x>dq_mn.back().second) {
                dq_mn.push_back(p);
            }
            else {
                while(dq_mn.size()!=0 && x<=dq_mn.back().second) {
                    dq_mn.pop_back();
                }
                dq_mn.push_back(p);
            }
            for(it=dq_mn.begin(); it!=dq_mn.end(); ++it) {
                if(j-dq_mn.front().first>=d) {
                    dq_mn.pop_front();
                }
            }
            ara_mn[j] = dq_mn.front().second;
            //mn
        }
        int mx_dif=-1;
        for(int j=0; j<n; j++) {
            if(ara_mx[j]-ara_mn[j]>mx_dif) mx_dif = ara_mx[j]-ara_mn[j];
        }
        printf("Case %d: %d\n", i+1, mx_dif);
    }
    return 0;
}
