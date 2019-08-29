/// Reference: https://www.quora.com/How-do-I-find-the-diameter-of-a-tree
/// We choose an arbitrary node (x) and find the farthest node from (x), let it be (y) (first bfs)
/// then we do another traversal to find the farthest node from (y) , let it be (z).     (second bfs)
/// Then diameter is the distance between (y) and (z).

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define SIZE 100005

vector<int> G[SIZE];    /// graph

int dist[SIZE];         /// distance array (number of nodes in the path from root)

int n;                  /// number of nodes

queue<int> Q;

pii bfs(int root) {
    memset(dist, 0, sizeof(dist));

    while(!Q.empty()) Q.pop();

    dist[root] = 1;
    Q.push(root);
    while(!Q.empty()) {
        int curr = Q.front();
        Q.pop();
        for(int i=0; i<G[curr].size(); i++) {
            int next = G[curr][i];
            if(dist[next]!=0) continue;

            dist[next] = dist[curr] + 1;
            Q.push(next);
        }
    }

    int mx = 0, mxVertex = -1;
    for(int i=1; i<=n; i++) {
        if(dist[i]>mx) {
            mx = dist[i];
            mxVertex = i;
        }
    }

    return pii(mx, mxVertex);  /// return the number of nodes in the max path and the farthest node
}

int findDiameter(int root) {
    pii p1, p2;
    p1 = bfs(root); /// bfs from root, p1.second is the farthest node from root
    p2 = bfs(p1.second); /// bfs from p1.second, p2.first is the diameter of the tree.

    return p2.first;
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> n;
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    cout << findDiameter(1) << "\n";

    return 0;
}

