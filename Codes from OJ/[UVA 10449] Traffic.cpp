/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;

#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MP make_pair
#define ff first
#define ss second
#define LL long long                        /// Note: 0-indexed
typedef pair < pair<LL, LL>, LL> plll;      /// dis[node] = inf (cannot reach), dis[node] = -inf (in a neg. cycle)
const LL inf = 1000000000000;               /// Modify if needed

#define SIZE 205                            /// Modify size accordingly

int ks;
LL buzzy[SIZE];                             /// buzziness is increased at night ;)
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

void solve() {
    for(int i=0; i<N; i++) {
        cin >> buzzy[i];
    }
    cin >> M;
    edgeVec.clear();
    for(int i=0; i<M; i++) {
        LL u, v;
        cin >> u >> v; u--; v--;
        LL cost = ((buzzy[v]-buzzy[u])*(buzzy[v]-buzzy[u])*(buzzy[v]-buzzy[u]));
        edgeVec.push_back(MP(MP(u, v), cost));

    }

    bellmanFord(0);

    cout << "Set #" << ks << "\n";
    int q;
    cin >> q;
    for(int i=0; i<q; i++) {
        int x;
        cin >> x; x--;
        if(dis[x]<3 || dis[x]==inf) {
            cout << "?\n";
        }
        else {
            cout << dis[x] << "\n";
        }
    }
}

int main () {
    fast_cin;

    ks = 1;
    while(cin >> N) {
        solve();
        ks++;
    }

    return 0;
}
