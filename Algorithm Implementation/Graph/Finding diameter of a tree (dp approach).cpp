// Reference: https://www.quora.com/How-do-I-find-the-diameter-of-a-tree

#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005

vector<int> G[SIZE];    // graph

int h[SIZE];        // height array

int n;       // number of node

// finding height of each node
int findHeight(int curr, int p) { // current node and its parent
    for(int i=0; i<G[curr].size(); i++) {
        int next = G[curr][i];
        if(next==p) continue; // height of the current node is the maximum height
                              // among its children + 1
        h[curr] = max(h[curr], findHeight(next, curr));
    }

    h[curr] += 1;

    return h[curr];
}

// finding diameter of a tree
// 1. Diameter may passes through the current node (mx1 + mx2 + 1)
// 2. Diameter may be present in any subtree of the current node's children. (mx_subtree)
int findDiameter(int curr, int p) {
    int mx1, mx2, mx_subtree;
    mx1 = mx2 = mx_subtree = 0;

    for(int i=0; i<G[curr].size(); i++) {
        int next = G[curr][i];      // determining 1st max and 2nd max heights
        if(next==p) continue;

        if(h[next]>mx1) {
            mx2 = mx1;
            mx1 = h[next];
        }
        else if(h[next]>mx2) {
            mx2 = h[next];
        }
    }

    for(int i=0; i<G[curr].size(); i++) {
        int next = G[curr][i];      // determining mx_subtree
        if(next==p) continue;

        mx_subtree = max(mx_subtree, findDiameter(next, curr));
    }

    return max(mx_subtree, mx1+mx2+1); // return maximum of the 2 cases
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

    findHeight(1, -1);                      // 1 based
    cout << findDiameter(1, -1) << "\n";    // 1 based

    return 0;
}
