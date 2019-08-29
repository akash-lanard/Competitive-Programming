/// Reference: https://www.geeksforgeeks.org/eulerian-path-and-circuit/

#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005

vector<int> G[SIZE];    /// Graph
int V;                  /// number of vertices
int E;                  /// number of edges
int visited[SIZE];      /// visited array

void dfs(int curr)  {
    visited[curr] = true;   /// visit current node

    for(int i=0; i<G[curr].size(); i++) {
        int next = G[curr][i];

        if(!visited[next]) {
            dfs(next);      /// if next is not visited go to next
        }
    }
}

/// checks if if all non-zero degree vertices are connected
/// It mainly does DFS traversal starting from a non-zero degree node
bool isConnected() {
    memset(visited, 0, sizeof(visited));/// initially all of them are non-visited

    int i;
    for(i=0; i<V; i++) {                /// Find a vertex with non-zero degree (*zero indexed)
        if(G[i].size()>0) break;
    }

    if(i==V) return true;               /// If there are no non-zero degree edges in the graph, return true

    dfs(i);                             /// Start DFS traversal from a vertex with non-zero degree

    for(i=0; i<V; i++) {                /// 0 indexed
        if(!visited[i] && G[i].size()>0) {
            return false;               /// Check if all non-zero degree vertices are visited
        }
    }

    return true;
}

/// The function returns one of the following values
/// 0 --> If graph is not Eulerian
/// 1 --> If graph has an Euler path (Semi-Eulerian)
/// 2 --> If graph has an Euler Circuit (Eulerian)
int isEulerian() {
    if(!isConnected()) {        /// Check if all non-zero degree vertices are connected
        return 0;
    }

    int oddCnt = 0;             /// Count vertices with odd degree
    for(int i=0; i<V; i++) {    /// 0 indexed
        if(G[i].size()&1) {     /// same as x%2!=0 (checking odd)
            oddCnt++;
        }
    }


    if(oddCnt>2) {              /// If count is more than 2, then graph is not Eulerian
        return 0;
    }

    /// If odd count is 2, then semi-eulerian.
    /// If odd count is 0, then eulerian
    /// Note that odd count can never be 1 for undirected graph
    return (oddCnt)? 1 : 2;
}

int main() {
    //freopen("input.txt", "r", stdin);

    cin >> V >> E;
    for(int i=0; i<E; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int res = isEulerian();
    if(res==0) {
        cout << "Graph is no Eulerian\n";
    }
    else if(res==1) {
        cout << "Graph has a Euler Path\n";
    }
    else {
        cout << "Graph has a Euler Cycle\n";
    }

    return 0;
}
