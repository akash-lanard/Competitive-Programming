// Reference: https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
/*
Depth First Traversal can be used to detect a cycle in a Graph.
DFS for a connected graph produces a tree. There is a cycle in
a graph only if there is a back edge present in the graph.
A back edge is an edge that is from a node to itself (self-loop)
or one of its ancestor in the tree produced by DFS.

For a disconnected graph, we get the DFS forest as output.
To detect cycle, we can check for a cycle in individual trees by checking back edges.

To detect a back edge, we can keep track of vertices currently in recursion stack
of function for DFS traversal. If we reach a vertex that is already in the recursion stack,
then there is a cycle in the tree. The edge that connects current vertex to the vertex
in the recursion stack is a back edge. We have used recStack[] array to keep
track of vertices in the recursion stack.
*/

#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005

vector<int> G[SIZE];

int n, m;               // number of node, number of edges

int visited[SIZE];      // visited arrray
int recStack[SIZE];     // recursion stack (1 if it is in the recursion stack)

bool isCyclicDirUtil(int curr) {
    if(!visited[curr]) {
        visited[curr] = 1;
        recStack[curr] = 1;

        for(int i=0; i<G[curr].size(); i++) {
            int next = G[curr][i];

            if(!visited[next] && isCyclicDirUtil(next)) {   // found a back edge in the child's subtree
                return true;
            }
            else if(recStack[next]) {   // if it is in the recursion stack, it found a back edge
                return true;
            }
        }
    }
    recStack[curr] = 0;
    return false;
}

bool isCyclicDir() {
    memset(visited, 0, sizeof(visited));
    memset(recStack, 0, sizeof(recStack));

    for(int i=0; i<n; i++) {
        if(isCyclicDirUtil(i)) {    // check for all the nodes (handles for disconnected graph (DFS forest))
            return true;
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
