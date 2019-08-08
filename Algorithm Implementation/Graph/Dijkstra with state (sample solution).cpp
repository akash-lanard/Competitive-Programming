///Problem link: https://codeforces.com/gym/101801 (Problem K)

#include <bits/stdc++.h>
using namespace std;

#define LL long long
typedef pair<int, int> pii;

#define SIZE 10005
#define BIG 1000000000000005

int N, M, K, S, E;

//vector is preferable
vector<int> Prime;
//int Prime[300000], nPrime;
//1 if not prime, 0 if prime
int mark[1000002];

void sieve(int n)
{
    int i, j, limit = sqrt(n*1.0) + 2;
    //1 is not prime
    mark[1] = 1;
    //evens
    for(i=4; i<=n; i+=2) mark[i] = 1;

    //2 is prime
    Prime.push_back(2);
    //run loops only on odds
    for(i=3; i<=n; i+=2) {
        if(!mark[i]) {
            Prime.push_back(i);

            //if we don't do it, following
            //i*i may overflow
            if(i<=limit) {
                for(j=i*i; j<=n; j += i*2) {
                    mark[j] = 1;
                }
            }
        }
    }
}

int altCost[1000005];
vector<int> pVec;

int calc(int n) {
    int temp = n;
    int lim = sqrt(n);
    pVec.clear();
    for(int i=0; Prime[i]<=lim; i++) {
        if(Prime[i]>temp) break;
        if(temp%Prime[i]==0) {
            pVec.push_back(Prime[i]);
            while(temp%Prime[i]==0) {
                temp /= Prime[i];
            }
        }
    }
    if(temp>1) pVec.push_back(temp);

    int ret = n;
    for(int i=0; i<pVec.size(); i++) {
        int curr = (n/pVec[i]) + (2*pVec[i]);
        ret = min(ret, curr);
    }

    return ret;
}

LL dis[105][SIZE];

struct Node
{
    int id, remK;
    LL cost;

    Node() {}

    Node(int id, int remK, LL cost)
    {
        this->id = id;
        this->remK = remK;
        this->cost = cost;
    }

    bool operator < (const Node &a)const {
        return cost > a.cost;
    }
};

vector<pii> G[SIZE];

priority_queue<Node> Q;

int vis[105][SIZE];

LL dijkstra(int source)
{
    LL ans = BIG;

    while(!Q.empty()) {
        Q.pop();
    }

    for(int i=0; i<105; i++) {
        for(int j=0; j<SIZE; j++) {
            dis[i][j] = BIG;
            vis[i][j] = 0;
        }
    }

    Node s(source, K, 0);

    Q.push(s);

    dis[K][source] = 0;

    while(!Q.empty()) {
        Node curr = Q.top();
        Q.pop();

        int u = curr.id;
        int remK = curr.remK;
        LL currDist = curr.cost;

        if(u==E) {
            ans = min(ans, currDist);
        }

        if(vis[remK][u]) continue;

        vis[remK][u] = true;

        for(int i=0; i<G[u].size(); i++) {
            int v = G[u][i].first;
            int cost = G[u][i].second;

            if(!vis[remK][v] && currDist+cost < dis[remK][v]) {
                dis[remK][v] = currDist+cost;

                Node n(v, remK, dis[remK][v]);

                Q.push(n);
            }

            if(remK<=0) continue;

            if(!vis[remK-1][v] && currDist+altCost[cost]<dis[remK-1][v]) {
                dis[remK-1][v] = currDist+altCost[cost];

                Node n(v, remK-1, dis[remK-1][v]);

                Q.push(n);
            }
        }
    }

    return ans;
}

void clr()
{
    for(int i=0; i<SIZE; i++) {
        G[i].clear();
    }
}

int main () {
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    //fast_cin;

    sieve(1000000);

    int tc;
    scanf("%d", &tc);
    for(int ks=1; ks<=tc; ks++) {
        clr();

        scanf("%d %d %d", &N, &M, &K);

        for(int i=1; i<=M; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);

            if(!altCost[w]) altCost[w] = calc(w);

            G[u].push_back(pii(v, w));
            G[v].push_back(pii(u, w));
        }

        scanf("%d %d", &S, &E);

        LL ans = dijkstra(S);

        if(ans==BIG) printf("-1\n");
        else printf("%lld\n", ans);
    }

    return 0;
}
