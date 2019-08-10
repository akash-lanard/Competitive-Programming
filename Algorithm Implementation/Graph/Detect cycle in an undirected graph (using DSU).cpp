// Reference: https://www.geeksforgeeks.org/union-find/
// Detects cycle in an undirected graph
// Notice: we assume that the graph does not contain any self loop
// and does not have multiple edge (simple graph). It also handles for disconnected graph.

#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005

typedef pair<int, int> pii;

int n, m; // number of nodes, number of edges
vector<pii> edgeVec;    // vector containing edges

// disjoint set codes
int parent[SIZE];

void makeset(int u) {
    parent[u] = u;
}

void init_disjoint_set(int N) {
    for(int i=0; i<=N; i++) {
        makeset(i);
    }
}

/*int FindRepresentative(int r) { //without path compression
    if(parent[r]==r) {
        return r;
    }
    return FindRepresentative(parent[r]);
}*/

int FindRepresentative(int r) { //with path compression
    if(parent[r]==r) {
        return r;
    }

    parent[r] = FindRepresentative(parent[r]);

    return parent[r];
}

void Union(int a, int b) {
    int u = FindRepresentative(a);
    int v = FindRepresentative(b);

    if(u!=v) {
        parent[u] = v;
    }
}
// end of disjoint set code

bool isCyclic() { // checks if the graph contains cycle
    init_disjoint_set(n+1);

    for(int i=0; i<edgeVec.size(); i++) {
        int x = FindRepresentative(edgeVec[i].first);
        int y = FindRepresentative(edgeVec[i].second);

        if(x==y) return true; // if both the nodes are in the same set, cycle exists

        Union(x, y);
    }

    return false;   // no cycle
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edgeVec.push_back(pii(u, v));
    }

    if(isCyclic()) {
        cout << "Graph contains cycle\n";
    }
    else {
        cout << "No cycle\n";
    }
}
