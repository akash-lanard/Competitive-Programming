// Call clear()
// Both sides have nodes starting from 1
// Call findMatching() to get maximum matching
// If Left[u] != 0 then (u and Left[u]) make a matching
// Complexity (sqrt(V)*E)

const int SIZE = 40005; // Maximum no of node(1 based indexing)

int n, m, A[SIZE], B[SIZE];
int Left[SIZE], Right[SIZE], dist[SIZE];
vector<int> G[SIZE];

struct HOPCROFT{
    int nNode, matching;

    void clear(int N){
        for(int i=0; i<=N; i++) G[i].clear();
        matching = 0;
        memset(Left, 0, sizeof(Left));
        memset(Right, 0, sizeof(Right));
        memset(dist, 0, sizeof(dist));
        nNode = N;
    }

    void addEdge(int u, int v){
        G[u].pb(v);
    }

    bool BFS() {
        queue<int> Q;
        for(int i=1; i<=nNode; i++) {
            if(Left[i] == 0) {
                dist[i] = 0;
                Q.push(i);
            }
            else {
                dist[i] = inf;
            }
        }
        dist[0] = inf;
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();
            if(u != 0) {
                int len = G[u].size();
                for(int i=0; i<len; i++) {
                    int v = G[u][i];
                    if(dist[Right[v]] == inf) {
                        dist[Right[v]] = dist[u] + 1;
                        Q.push(Right[v]);
                    }
                }
            }
        }
        return (dist[0] != inf);
    }

    bool DFS(int u) {
        if(u != 0) {
            int len = G[u].size();
            for(int i=0; i<len; i++) {
                int v = G[u][i];
                if(dist[Right[v]] == dist[u]+1) {
                    if(DFS(Right[v])) {
                        Right[v] = u;
                        Left[u] = v;
                        return true;
                    }
                }
            }
            dist[u] = inf;
            return false;
        }
        return true;
    }

    int findMatching() {
        while(BFS()){
            for(int i=1; i<=nNode; i++){
                if(Left[i] == 0 && DFS(i)){
                    matching++;
                }
            }
        }
        return matching;
    }
}hopcroft;
