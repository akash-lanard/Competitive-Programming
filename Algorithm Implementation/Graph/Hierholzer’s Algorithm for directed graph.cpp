/// Reference: https://www.geeksforgeeks.org/hierholzers-algorithm-directed-graph/
/// Time Complexity: O(V+E)

#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005     /// Change SIZE if needed

vector<int> G[SIZE];    /// Graph
int V;                  /// Number of vertices
int E;                  /// Number of edges
int edgeCnt[SIZE];      /// Count of edges to keep track of unused edges
stack<int> curr_path;   /// Maintain stack to keep vertices
vector<int> circuit;    /// vector to store final circuit

void printCircuit() {
    for(int i=0; i<V; i++) {        /// 0 indexed
        edgeCnt[i] = G[i].size();   /// get edgeCnt
    }

    if(V==0) return;

    while(!curr_path.empty()) {     /// clear curr_path stack
        curr_path.pop();
    }
    circuit.clear();                /// clear final circuit vector

    int v = 0;                      /// Get first non-zero degree vertex
    for(int i=0; i<V; i++) {        /// 0 indexed
        if(G[i].size()>0) break;
    }

    curr_path.push(v);              /// start from first non-zero degree vertex
    int curr_v = 0;                 /// current vertex

    while(!curr_path.empty()) {
        if(edgeCnt[curr_v]) {       /// If there's remaining edge
            curr_path.push(curr_v); /// Push the vertex

            int next_v = G[curr_v].back();/// Find the next vertex using an edge

            edgeCnt[curr_v]--;      /// and remove that edge
            G[curr_v].pop_back();

            curr_v = next_v;        /// Move to next vertex
        }
        else {                      /// back-track to find remaining circuit
            circuit.push_back(curr_v);/// Push to the final circuit

            curr_v = curr_path.top();/// Back-tracking
            curr_path.pop();
        }
    }

    /// We've got the circuit, now print in reverse
    for(int i=circuit.size()-1; i>=0; i--) {
        cout << circuit[i];
        if(i) cout << " -> ";
    }
    cout << "\n";
}

int main() {
    //freopen("input.txt", "r", stdin);

    cin >> V >> E;
    for(int i=0; i<E; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }

    printCircuit();

    return 0;
}
