// Reference: https://www.geeksforgeeks.org/euler-circuit-directed-graph/
// Time Complexity: O(V+E)

#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005     // Change SIZE if needed

vector<int> G[SIZE];    // Graph
int V;                  // Number of vertices
int E;                  // Number of edges
vector<int> T[SIZE];    // Transpose of G
int visited[SIZE];      // Visited Array
int inDeg[SIZE];        // In-degree

// A recursive function to do DFS starting from v in original graph
void dfs1(int curr) {
    visited[curr] = true;   // Mark the current node as visited

    for(int i=0; i<G[curr].size(); i++) {
        int next = G[curr][i];
        if(!visited[next]) {// Recur for all the vertices adjacent to this vertex
            dfs1(next);
        }
    }
}

// A recursive function to do DFS starting from v in transpose graph
void dfs2(int curr) {
    visited[curr] = true;   // Mark the current node as visited

    for(int i=0; i<T[curr].size(); i++) {
        int next = T[curr][i];
        if(!visited[next]) {// Recur for all the vertices adjacent to this vertex
            dfs2(next);
        }
    }
}

void getTranspose() {           // Generates the transpose of the Graph
    for(int i=0; i<SIZE; i++) {
        T[i].clear();           // clear the transpose graph
    }

    for(int i=0; i<V; i++) {    // 0 indexed
        for(int j=0; j<G[i].size(); j++) {
            int u = i;          // from (in the original graph)
            int v = G[i][j];    // to (in the original graph)

            T[v].push_back(u);  // to to from (reversed)
        }
    }
}

// This function returns true if all non-zero degree vertices of
// graph are strongly connected
bool isSC() {
    memset(visited, 0, sizeof(visited));// Mark all the vertices as not visited (For first DFS)

    int n;                  // Find the first vertex with non-zero degree
    for(n=0; n<V; n++) {    // 0 Indexed
        if(G[n].size()>0) break;
    }

    dfs1(n);         // Do DFS traversal starting from first non zero degrees vertex.

    for(int i=0; i<V; i++) {// 0 Indexed
        if(G[i].size()>0 && visited[i]==false) {
            return false;   // If DFS traversal doesn't visit all vertices, then return false.
        }
    }

    getTranspose(); // Create a reversed graph

    memset(visited, 0, sizeof(visited));// Mark all the vertices as not visited (For second DFS)

    dfs2(n);         // Do DFS for reversed graph starting from first vertex.
                    // Staring Vertex must be same starting point of first DFS

    for(int i=0; i<V; i++) {// 0 Indexed
        if(T[i].size()>0 && visited[i]==false) {
            return false;   // If second DFS traversal doesn't visit all vertices, then return false.
        }
    }

    return true;
}

/* This function returns true if the directed graph has a eulerian
   cycle, otherwise returns false*/
bool isEulerianCycle() {
    // Check if all non-zero degree vertices are connected
    if (isSC() == false) {
        return false;
    }

    // Check if in degree and out degree of every vertex is same
    for (int i = 0; i < V; i++) {    // 0 Indexed
        if (G[i].size() != inDeg[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    freopen("input.txt", "r", stdin);

    cin >> V >> E;
    for(int i=0; i<E; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        inDeg[v]++;
    }

    if(isEulerianCycle()) {
        cout << "Given directed graph is eulerian\n";
    }
    else {
        cout << "Given directed graph is NOT eulerian\n";;
    }

    return 0;
}
