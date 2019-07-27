#include <bits/stdc++.h>
using namespace std;

#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define LL long long

#define SIZE 205
#define BIG 1000000000000005

int N;                  /// number of nodes
LL G[SIZE][SIZE];       /// Matrix
LL dis[SIZE][SIZE];     /// distance matrix
bool dead[SIZE];        /// not go through dead ones
bool done[SIZE];        /// not try to go further if it is done
//int pre[SIZE][SIZE];

struct Node {
    int id;
    LL dist;

    Node() {}
    Node(int id, LL dist) {
        this->id = id;
        this->dist = dist;
    }
    bool operator < (const Node &a)const {
        return dist > a.dist;
    }
};

priority_queue<Node> Q;

//vector<pair<int, int> > G[SIZE];

void  dijkstra(int source) {
    while(!Q.empty()) Q.pop();
    memset(done, 0, sizeof(done));
    for(int i=0; i<SIZE; i++) {
        dis[source][i] = BIG;
        //pre[i] = -1;
    }

    Node s(source, 0);
    Q.push(s);
    dis[source][source] = 0;

    while(!Q.empty()) {
        Node curr = Q.top();
        Q.pop();

        int u = curr.id;
        LL curr_dist = curr.dist;

        if(curr_dist!=dis[source][u] || dead[u] || done[u]) continue;

        done[u] = 1;

        for(int i=0; i<N; i++) {
            int v = i;
            LL cost = G[u][i];

            if(!done[v] && dis[source][u]+cost < dis[source][v]) {
                dis[source][v] = dis[source][u] + cost;

                Node n(v, dis[source][v]);
                Q.push(n);
                //pre[v] = u;
            }
        }
    }
}

void clr()
{
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(i!=j) G[i][j] = BIG;
            else G[i][j] = 0;
        }
    }
}

struct R {
    int id;
    int risk;
    R() {}
    R(int id, int risk) {
        this->id = id;
        this->risk = risk;
    }
};

bool comp(const R &a, const R &b) {
    return a.risk>b.risk;
}

vector<R> RVec;


int main () {
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    //fast_cin;

    int tc;
    scanf("%d", &tc);
    for(int ks=1; ks<=tc; ks++) {
        clr();
        RVec.clear();

        int q;
        scanf("%d %d", &N, &q);

        for(int i=0; i<N; i++) {
            int r;
            scanf("%d", &r);
            RVec.push_back(R(i, r));
        }

        sort(RVec.begin(), RVec.end(), comp);

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                scanf("%lld", &G[i][j]);
            }
        }

        memset(dead, 0, sizeof(dead));

        for(int i=0; i<RVec.size(); i++) {
            dijkstra(RVec[i].id);
            dead[RVec[i].id] = true;
        }

        printf("Case #%d:\n", ks);

        for(int i=0; i<q; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);

            u--;
            v--;

            LL ans = min(G[u][v], G[v][u]);

            for(int j=RVec.size()-1; j>=0; j--) {
                if(RVec[j].risk>w) break;

                ans = min( ans, dis[RVec[j].id][u] + dis[RVec[j].id][v] );
            }

            printf("%lld\n", ans);
        }
    }

    return 0;
}

