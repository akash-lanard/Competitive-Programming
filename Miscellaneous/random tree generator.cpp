// generating a tree in a simple way
#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); /// For generating random numbers

int rand(int a, int b) {
    return a + rng() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    int n = rand(2, 20);
    printf("%d\n", n);
    for(int i = 2; i <= n; ++i) {
        printf("%d %d\n", rand(1, i - 1), i);
    }
}
