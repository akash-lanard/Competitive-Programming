#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005

int N;
vector<int> G[SIZE];

bool DLS(int source, int target, int limit) {
    if(source==target) {
        return true;
    }

    if(limit<=0) {
        return false;
    }

    for(int i=0; i<G[source].size(); i++) {
        int next = G[source][i];
        if(DLS(next, target, limit-1)) return true;
    }

    return false;
}

bool IDDFS(int source, int target, int max_depth) {
    for(int i=0; i<=max_depth; i++) {
        if(DLS(source, target, i)) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    N = 7;

    G[0].push_back(1);
    G[0].push_back(2);
    G[1].push_back(3);
    G[1].push_back(4);
    G[2].push_back(5);
    G[2].push_back(6);

    int target = 6, maxDepth = 3, src = 0;

    if (IDDFS(src, target, maxDepth) == true) {
        cout << "Target is reachable from source within max depth\n";
    }
    else {
        cout << "Target is NOT reachable from source within max depth\n";
    }

    return 0;
}
