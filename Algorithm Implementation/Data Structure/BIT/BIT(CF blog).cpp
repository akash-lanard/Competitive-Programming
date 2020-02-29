/// Source: https://codeforces.com/blog/entry/15729

#include <bits/stdc++.h>
using namespace std;

/// Basic BIT/Fenwick tree
/// Initilize N, update and query (point update, range sum query)
/// While updating range handle index accordingly
/// Note: always 1-indexed
#define SIZE 100005 /// Update if needed

int N; /// Number of elements
int fen[SIZE];

void update(int p, int val) { /// update value to val at position p (1-indexed)
    for(int i=p; i<=N; i += i&-i) { ///i + (i AND 1's complement of i)
        fen[i] += val;
    }
}

int sum(int p) { /// prefix sum(1-p) at position p (1-indexed)
    int ans = 0;
    for(int i=p; i; i -= i&-i) { ///i - (i AND 1's complement of i)
        ans += fen[i];
    }
    return ans;
}

int main () {
    N = 5;

    /// Array elements: 1, 2, 3, 4, 5 (1-indexed)
    update(1, 1);
    update(2, 2);
    update(3, 3);
    update(4, 4);
    update(5, 5);

    cout << sum(1) - sum(0) << endl;
    cout << sum(3) - sum(1) << endl;
    cout << sum(5) - sum(2) << endl;

    return 0;
}

