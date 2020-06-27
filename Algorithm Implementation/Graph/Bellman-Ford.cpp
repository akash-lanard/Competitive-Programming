#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define ff first
#define ss second
#define LL long long                        /// Note: 0-indexed
typedef pair < pair<LL, LL>, LL> plll;      /// dis[node] = inf (cannot reach), dis[node] = -inf (in a neg. cycle)
const LL inf = 1000000000000;               /// Modify if needed

#define SIZE 200005                         /// Modify size accordingly

LL N, M, dis[SIZE];                         /// num. of nodes, num. of edges, distance array, cost of edges
vector<plll> edgeVec;                       /// Edge vector

void bellmanFord(int src) {
    for(int i=0; i<N; i++) {
        dis[i] = inf;                       /// initially inf
    }

    dis[src] = 0;                           /// dist. of src
    for(int i=0; i<N-1; i++) {              /// Relax N-1 times
        bool upd = false;
        for(int j=0; j<M; j++) {            /// all the edges
            int u = edgeVec[j].ff.ff, v = edgeVec[j].ff.ss, cost = edgeVec[j].ss;
            if(dis[u]!=inf && dis[u]+cost<dis[v]) {
                dis[v] = dis[u] + cost;
                upd = true;                 /// update is done
            }
        }
        if(!upd) break;                     /// break if no update
    }

    for(int i=0; i<M; i++) {                /// check if the node is in a negative cycle
        int u = edgeVec[i].ff.ff, v = edgeVec[i].ff.ss, cost = edgeVec[i].ss;
        if(dis[u]!=inf && dis[u]+cost<dis[v]) {
            dis[v] = -inf;
        }
    }
}

int main () {

    return 0;
}
