// Reference: https://www.geeksforgeeks.org/strongly-connected-components/

#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005

vector<int> G[SIZE];// Graph
vector<int> T[SIZE];// Transpose of the Graph
int V;              // number of vertices
int E;              // number of edges
int visited[SIZE];  // visited array
stack<int> S;       // stack (stores vertices with increasing order of finishing time)
                    // (top has the maximum finishing time)

// A recursive function to print DFS starting from v
void dfs(int curr) {
    visited[curr] = true;   // Mark the current node as visited and print it
    cout << curr << " ";

    for(int i=0; i<T[curr].size(); i++) {
        int next = T[curr][i];
        if(!visited[next]) {// Recur for all the vertices adjacent to this vertex
            dfs(next);
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

// Fills Stack with vertices (in increasing order of finishing times)
// The top element of stack has the maximum finishing time
void fillStack(int curr) {
    visited[curr] = true;       // Mark the current node as visited

    for(int i=0; i<G[curr].size(); i++) {
        int next = G[curr][i];  // Recur for all the vertices adjacent to this vertex
        if(!visited[next]) {
            fillStack(next);
        }
    }

    S.push(curr);               // All vertices reachable from v are processed by now, push v
}

void GetSCCs() {
    while(!S.empty()) S.pop();          // empty the stack

    memset(visited, 0, sizeof(visited));// Mark all the vertices as not visited (For first DFS)

    for(int i=0; i<V; i++) {            // 0 indexed
        if(!visited[i]) {               // Fill vertices in stack according to their finishing times
            fillStack(i);
        }
    }

    getTranspose();                     // Generate the reversed graph T

    memset(visited, 0, sizeof(visited));// Mark all the vertices as not visited (For second DFS)

    while(!S.empty()) {                 // Now process all vertices in order defined by Stack
        int curr = S.top();
        S.pop();                        // Pop a vertex from stack

        if(!visited[curr]) {
            dfs(curr);                  // Print Strongly connected component of the popped vertex
            cout << "\n";
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> V >> E;
    for(int i=0; i<E; i++) {
        int u, v;
        cin >> u >> v;

        G[u].push_back(v);
    }

    cout << "Following are strongly connected components in the given graph:\n";
    GetSCCs();

    return 0;
}
