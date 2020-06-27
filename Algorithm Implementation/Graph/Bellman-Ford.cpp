#define ff first
#define ss second
#define LL long long                    /// Note: 0-indexed
typedef pair < int, int > pii;          /// dis[node] = inf (cannot reach), dis[node] = -inf (in a neg. cycle)
const LL inf = 2147383647;              /// Modify if needed

#define SIZE 205                        /// Modify size accordingly

LL N, M, dis[SIZE], cost_uv[200005];    /// num. of nodes, num. of edges, distance array, cost of edges (modify size if needed)
vector<pii> edgeVec;                    /// Edge vector (can also use struct including the edge costs)

void bellmanFord(int src) {
    for(int i=0; i<N; i++) {
        dis[i] = inf;                   /// initially inf
    }

    dis[src] = 0;                       /// dist. of src
    for(int i=0; i<N-1; i++) {          /// Relax N-1 times
        bool upd = false;
        for(int j=0; j<M; j++) {        /// all the edges
            int u = edgeVec[j].ff, v = edgeVec[j].ss;
            if(dis[u]!=inf && dis[u]+cost_uv[j]<dis[v]) {
                dis[v] = dis[u] + cost_uv[j];
                upd = true;             /// update is done
            }
        }
        if(!upd) break;                 /// break if no update
    }

    for(int i=0; i<M; i++) {            /// check if the node is in a negative cycle
        int u = edgeVec[i].ff, v = edgeVec[i].ss;
        if(dis[u]!=inf && dis[u]+cost_uv[i]<dis[v]) {
            dis[v] = -inf;
        }
    }
}
