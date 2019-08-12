// Reference: https://www.geeksforgeeks.org/diameter-tree-using-dfs/
/*Same idea as bfs approach
We choose an arbitrary node (x) and find the farthest node from (x), let it be (y) (first dfs)
then we do another traversal to find the farthest node from (y) , let it be (z).   (second dfs)
Then diameter is the distance between (y) and (z)*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

#define SIZE 100005

vector<int> G[SIZE];    // graph

int visited[SIZE];      // visited array

int n;                  // number of nodes

int mxCnt;              // global variable to determine diameter
int fn;                 // global variable to determine farthest node

void dfs(int curr, int cnt) {
    visited[curr] = 1;
    cnt++;
    if(cnt>mxCnt) {
        mxCnt = cnt;
        fn = curr;
    }
    for(int i=0; i<G[curr].size(); i++) {
        int next = G[curr][i];

        if(!visited[next]) {
            dfs(next, cnt);
        }
    }
}

int findDiameter() {
    mxCnt = 0;

    memset(visited, 0, sizeof(visited));
    dfs(1, 0);  // first bfs from a random node (here it is 1)

    memset(visited, 0, sizeof(visited));
    dfs(fn, 0); // second bfs from fn

    return mxCnt;   // mxCnt is the diameter
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> n;
    for(int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    cout << findDiameter() << "\n";

    return 0;
}


