#include <bits/stdc++.h>
using namespace std;

#define SIZE 105

vector<int> G[SIZE];

vector<int> L;

queue<int> Q;

int inDegree[SIZE];

void topsort(int N)
{
    L.clear();
    while(!Q.empty()) Q.pop();

    for(int i=1; i<=N; i++) {
        if(inDegree[i]==0) {
            Q.push(i);
        }
    }

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();

        L.push_back(u);

        for(int i=0; i<G[u].size(); i++) {
            int v = G[u][i];
            inDegree[v]--;
            if(inDegree[v]==0) {
                Q.push(v);
            }
        }
    }
}

void clr()
{
    for(int i=0; i<SIZE; i++) G[i].clear();
    memset(inDegree, 0, sizeof(inDegree));
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int n, m;
    while(1) {
        scanf("%d %d", &n, &m);
        if(n==0 & m==0) break;

        clr();

        for(int i=0; i<m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            inDegree[v]++;
        }

        topsort(n);

        for(int i=0; i<L.size(); i++) {
            if(i==0) printf("%d", L[i]);
            else printf(" %d", L[i]);
        }
        printf("\n");
    }

    return 0;
}
