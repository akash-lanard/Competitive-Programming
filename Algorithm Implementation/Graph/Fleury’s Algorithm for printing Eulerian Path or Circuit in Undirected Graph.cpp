/// Reference: https://www.geeksforgeeks.org/fleurys-algorithm-for-printing-eulerian-path/
/// Time Complexity: O((V+E)^2)

#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005     /// change SIZE if needed

vector<int> G[SIZE];    /// Graph
int V;                  /// Number of vertices
int E;                  /// Number of edges
int visited[SIZE];      /// Visited Array

/// A DFS based function to count reachable vertices from curr
int DFSCount(int curr) {
    visited[curr] = 1;  /// Mark the current node as visited
    int cnt = 1;

    for(int i=0; i<G[curr].size(); i++) {
        int next = G[curr][i];  /// Recur for all vertices adjacent to this vertex
        if(next!=-1 && !visited[next]) {
            cnt += DFSCount(next);
        }
    }

    return cnt;
}

/// This function removes edge u-v from graph.  It removes the edge by
/// replacing adjcent vertex value with -1.
void rmvEdge(int u, int v) {
    /// Find v in adjacency list of u and replace it with -1
    vector<int>::iterator iv = find(G[u].begin(), G[u].end(), v);
    *iv = -1;

    /// Find u in adjacency list of v and replace it with -1
    vector<int>::iterator iu = find(G[v].begin(), G[v].end(), u);
    *iu = -1;
}

/// The function to check if edge u-v can be considered as next edge in
/// Euler Tour
bool isValidNextEdge(int u, int v) {
    /// The edge u-v is valid in one of the following two cases:

    /// 1) If v is the only adjacent vertex of u
    int cnt = 0;    /// To store count of adjacent vertices
    for(int i=0; i<G[u].size(); i++) {
        if(G[u][i]!=-1) cnt++;
    }
    if(cnt==1) return true;

    /// 2) If there are multiple adjacents, then u-v is not a bridge
    /// Do following steps to check if u-v is a bridge

    /// 2.a) count of vertices reachable from u
    memset(visited, 0, sizeof(visited));
    int cnt1 = DFSCount(u);

    /// 2.b) Remove edge (u, v) and after removing the edge, count
    /// vertices reachable from u
    rmvEdge(u, v);
    memset(visited, 0, sizeof(visited));
    int cnt2 = DFSCount(u);

    /// 2.c) Add the edge back to the graph
    G[u].push_back(v);

    /// 2.d) If count1 is greater, then edge (u, v) is a bridge
    return (cnt1>cnt2)? false:true;
}

/// Print Euler tour starting from vertex u
void printEulerUtil(int curr) {
    for(int i=0; i<G[curr].size(); i++) {/// Recur for all the vertices adjacent to this vertex
        int next = G[curr][i];/// If edge u-v is not removed and it's a a valid next edge
        if(next!=-1 && isValidNextEdge(curr, next)) {
            cout << curr << "-" << next << " ";
            rmvEdge(curr, next);
            printEulerUtil(next);
        }
    }
}

/// The main function that print Eulerian Trail. It first finds an odd
/// degree vertex (if there is any) and then calls printEulerUtil()
/// to print the path
void printEulerTour() {
    int u = 0;

    for(int i=0; i<V; i++) {
        if(G[i].size()>0) {
            u = i;
            break;
        }
    }

    for(int i=0; i<V; i++) {
        if(G[i].size() & 1) {   /// Find a vertex with odd degree
            u = i;
            break;
        }
    }

    printEulerUtil(u);          /// Print tour starting from oddv
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    freopen("input.txt", "r", stdin);

    cin >> V >> E;
    for(int i=0; i<E; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    printEulerTour();

    return 0;
}
