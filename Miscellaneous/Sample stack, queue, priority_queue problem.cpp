#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF) {
        int flag_s=1, flag_q=1, flag_pq=1;
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        for(int i=0; i<n; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            if(a==1) {
                s.push(b);
                q.push(b);
                pq.push(b);
            }
            else if(a==2) {
                if(flag_s) {
                    if(s.size()==0 || s.top()!=b) flag_s = 0;
                    else s.pop();
                }
                if(flag_q) {
                    if(q.size()==0 || q.front()!=b) flag_q = 0;
                    else q.pop();
                }
                if(flag_pq) {
                    if(pq.size()==0 || pq.top()!=b) flag_pq = 0;
                    else pq.pop();
                }

            }
        }

        //printf("flag_s = %d, flag_q = %d, flag_pq = %d\n", flag_s, flag_q, flag_pq);

        if(flag_pq+flag_q+flag_s==0) printf("impossible\n");
        else if(flag_pq+flag_q+flag_s>1) printf("not sure\n");
        else if(flag_s) printf("stack\n");
        else if(flag_q) printf("queue\n");
        else if(flag_pq) printf("priority queue\n");
    }
    return 0;
}
