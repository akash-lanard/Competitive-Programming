// generating a tree in a not-so-stupid way
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); /// For generating random numbers

int rand(int a, int b) {
    return a + rng() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    int n = rand(2, 20);
    printf("%d\n", n);
    vector<pair<int,int>> edges;
    for(int i = 2; i <= n; ++i) {
        edges.emplace_back(rand(1, i - 1), i);
    }

    vector<int> perm(n + 1); // re-naming vertices
    for(int i = 1; i <= n; ++i) {
        perm[i] = i;
    }
    random_shuffle(perm.begin() + 1, perm.end());

    random_shuffle(edges.begin(), edges.end()); // random order of edges

    for(pair<int, int> edge : edges) {
        int a = edge.first, b = edge.second;
        if(rng() % 2) {
            swap(a, b); // random order of two vertices
        }
        printf("%d %d\n", perm[a], perm[b]);
    }
}
