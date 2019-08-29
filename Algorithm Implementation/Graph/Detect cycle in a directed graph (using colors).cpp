/// Reference: https://www.geeksforgeeks.org/detect-cycle-direct-graph-using-colors

/// Same as DFS solution. This solution uses colors to find cycle (The solution is from CLRS book)
/// The idea is to do DFS of given graph and while doing traversal, assign one of the below three colors to every vertex
/// WHITE : Vertex is not processed yet.  Initially
///         all vertices are WHITE.
///
/// GRAY : Vertex is being processed (DFS for this          (going to GREY means back edge)
///        vertex has started, but not finished which means
///        that all descendants (ind DFS tree) of this vertex
///        are not processed yet (or this vertex is in function
///        call stack)
/// 
/// BLACK : Vertex and all its descendants are   (going to BLACK means forward edge / cross edge)
///         processed.
/// 
/// While doing DFS, if we encounter an edge from current
/// vertex to a GRAY vertex, then this edge is back edge
/// and hence there is a cycle.

#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005

enum Color {WHITE, GREY, BLACK};

vector<int> G[SIZE];    /// Graph

int n, m;                  /// number of nodes, number of edges

int color[SIZE];        /// using color array instead of visited and recStack

bool isCyclicDirUtil(int curr) {
    color[curr] = GREY;         /// this vertex is being processed

    for(int i=0; i<G[curr].size(); i++) {
        int next = G[curr][i];

        if(color[next]==GREY) {
            return true;        /// we found a back edge (cycle exists)
        }
        else if(color[next]==WHITE && isCyclicDirUtil(next)) {
            return true;        /// we found a back edge in the children's subtree
        }
    }

    color[curr] = BLACK;       /// Vertex and all its descendants are processed

    return false;
}

bool isCyclicDir() {
    for(int i=0; i<=n; i++) {
        color[i] = WHITE;       /// all the nodes are whites initially (not processed)
    }

    for(int i=0; i<n; i++) {
        if(color[i]==WHITE) {     /// this vertex is not processed
            if(isCyclicDirUtil(i)) {    /// check for all the unprocessed nodes (handles for disconnected graph (DFS forest))
                return true;
            }
        }
    }

    return false;
}

void clr() {
    for(int i=0; i<SIZE; i++) {
        G[i].clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    clr();

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }

    if(isCyclicDir()) {
        cout << "Graph contains cycle\n";
    }
    else {
        cout << "Graph doesn't contain cycle\n";
    }

    return 0;
}
