#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005

int parent[SIZE];
int sz[SIZE];

void makeset(int u) {
    parent[u] = u;
    sz[u] = 1;
}

void init_disjoint_set(int N) {
    for(int i=0; i<=N; i++) {
        makeset(i);
    }
}

int FindRepresentative(int r) {  //with path compression
    if(parent[r]==r) {
        return r;
    }

    parent[r] = FindRepresentative(parent[r]);

    return parent[r];
}

int FindSize(int r) {
    return sz[FindRepresentative(r)];
}

void Union(int a, int b) {
    int u = FindRepresentative(a);
    int v = FindRepresentative(b);

    if(u!=v) {
        if(sz[v]>=sz[u]) {
            parent[u] = v;
            sz[v] += sz[u];
        }
        else {
           parent[v] = u;
            sz[u] += sz[v];
        }
    }
}

int main () {
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    //fast_cin;

    init_disjoint_set(10);

    Union(1, 2);
    Union(1, 3);

    Union(4, 5);

    Union(2, 5);

    cout << FindSize(5) << endl;

    return 0;
}

