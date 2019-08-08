#include <bits/stdc++.h>
using namespace std;

#define SIZE 100002

int arr[SIZE];
int tree[SIZE*4];

void init(int node, int b, int e) {
    if(b==e) {
        tree[node] = arr[b];
        return;
    }

    int Left = node*2;
    int Right = node*2 + 1;

    int mid = (b+e) / 2;

    init(Left, b, mid);
    init(Right, mid+1, e);

    tree[node] = tree[Left] + tree[Right];
}

int query(int node, int b, int e, int i, int j) {
    if(e<i || j<b) {
        return 0;
    }
    if(i<=b && e<=j) {
        return tree[node];
    }

    int Left = node*2;
    int Right = node*2 + 1;

    int mid = (b+e)/2;

    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid+1, e, i, j);

    return p1+p2;
}

void update(int node, int b, int e, int i, int newVal) {
    if(e<i || i<b) {
        return;
    }
    if(i<=b && e<=i) {
        tree[node] = newVal;
        return;
    }

    int Left = node*2;
    int Right = node*2 + 1;

    int mid = (b+e)/2;

    update(Left, b, mid, i, newVal);
    update(Right, mid+1, e, i, newVal);

    tree[node] = tree[Left] + tree[Right];
}

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    init(1, 1, n);

    int q;
    cin >> q;
    for(int i=1; i<=q; i++) {
        int qtype;
        cin >> qtype;
        if(qtype==0) {
            int indx, newVal;
            cin >> indx >> newVal;
            update(1, 1, n, indx, newVal);
        }
        else if(qtype==1) {
            int l, r;
            cin >> l >> r;
            int ret = query(1, 1, n, l, r);
            cout << ret << "\n";
        }
    }

    return 0;
}
