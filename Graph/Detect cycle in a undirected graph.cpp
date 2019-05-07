#include <bits/stdc++.h>
using namespace std;

/*
We can use DFS to detect cycle in an undirected graph in O(V+E) time.
We do a DFS traversal of the given graph. For every visited vertex ‘v’,
if there is an adjacent ‘u’ such that u is already visited and u is not parent of v,
then there is a cycle in graph. If we don’t find such an adjacent for any vertex,
we say that there is no cycle. The assumption of this approach is that there are
no parallel edges between any two vertices.
*/

#define SIZE 100005

vector<int> G[SIZE];

int N;

int visited[SIZE];

bool isCyclicUndirUtil(int curr, int prev) {
    visited[curr] = 1;

    for(int i=0; i<G[curr].size(); i++) {
        int next = G[curr][i];

        if(!visited[next]) {
            if(isCyclicUndirUtil(next, curr)) return true;
        }
        else if(next!=prev) {
            return true;
        }
    }

    return false;
}

bool isCyclicUndir() {
    memset(visited, 0, sizeof(visited));

    for(int i=0; i<N; i++) {
        if(!visited[i]) {
            if(isCyclicUndirUtil(i, -1)) return true;
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

    N = 5;

    G[0].push_back(1);
    G[1].push_back(0);
    G[0].push_back(2);
    G[2].push_back(0);
    G[1].push_back(2);
    G[2].push_back(1);
    G[0].push_back(3);
    G[3].push_back(0);
    G[3].push_back(4);
    G[4].push_back(3);

    if(isCyclicUndir()) {
        cout << "Graph contains cycle\n";
    }
    else {
        cout << "Graph doesn't contain cycle\n";
    }

    clr();

    N = 3;

    G[0].push_back(1);
    G[1].push_back(0);
    G[1].push_back(2);
    G[2].push_back(1);

    if(isCyclicUndir()) {
        cout << "Graph contains cycle\n";
    }
    else {
        cout << "Graph doesn't contain cycle\n";
    }

    return 0;
}

