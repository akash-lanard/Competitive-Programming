/// Reference: https://www.geeksforgeeks.org/detect-cycle-in-an-undirected-graph-using-bfs/ 
/// almost similiar to DFS method, parent array is needed here

#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005
#define BIG 100000000

int n, m;       /// number of vertices and number of edges

vector<int> G[SIZE];   /// Graph
int visited[SIZE];     /// visited array instead of level (here distance is not an issue)
int parent[SIZE];      /// in BFS parents of each vertex need to be tracked

queue<int> Q;

bool BFS(int source) {
    while(!Q.empty()) Q.pop();

    visited[source] = 1; /// mark the source as visited
    Q.push(source);      /// push source node in queue

    while(!Q.empty()) {
        int curr = Q.front();   /// curr node in the front of the queue, pop it
        Q.pop();

        for(int i = 0; i<G[curr].size(); i++) {
            int next = G[curr][i];
            if(!visited[next]) {    /// if next node is not updated update it
                visited[next] = 1;  /// next node is visited
                Q.push(next);       /// push next in the queue
                parent[next] = curr;// parent of next is updated
            }
            else if(next!=parent[curr]) {
                return true;        /// if next is visited but it is not parent of curr than cycle exists
            }
        }
    }
    return false;
}

bool isCyclic() {
    memset(visited, 0, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    for(int i=0; i<n; i++) { /// change here if vertices are 1 indexed
        if(!visited[i] && BFS(i)) {
            return true;
        }
    }

    return false;
}

void clr() {
    for(int i=0; i<SIZE; i++) G[i].clear();
}


int main() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    if(isCyclic()) {
        cout << "Graph contains cycle\n";
    }
    else {
        cout << "No cycle\n";
    }

    return 0;
}
