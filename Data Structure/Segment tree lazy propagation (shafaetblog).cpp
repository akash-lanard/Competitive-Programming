#include <bits/stdc++.h>
using namespace std;

#define LL long long

#define SIZE 100002

int arr[SIZE];

struct info {
    LL prop, sum;
} tree[SIZE*4];

void init(int node, int b, int e) {
    if(b==e) {
        tree[node].sum = arr[b];
        return;
    }

    int Left = node*2;
    int Right = node*2 + 1;

    int mid = (b+e) / 2;

    init(Left, b, mid);
    init(Right, mid+1, e);

    tree[node].sum = tree[Left].sum + tree[Right].sum;
}

void update(int node, int b, int e, int i, int j, LL x) {
    if(e<i || j<b) {
        return;
    }
    if(i<=b && e<=j) {
        tree[node].sum += ((e-b+1)*x);
        tree[node].prop += x;
        return;
    }

    int Left = node*2;
    int Right = node*2 + 1;

    int mid = (b+e)/2;

    update(Left, b, mid, i, j, x);
    update(Right, mid+1, e, i, j, x);

    tree[node].sum = tree[Left].sum + tree[Right].sum + ((e-b+1)*tree[node].prop);
}

LL query(int node, int b, int e, int i, int j, LL carry=0) {
    if(e<i || j<b) {
        return 0;
    }
    if(i<=b && e<=j) {
        return tree[node].sum + carry*(e-b+1);
    }

    int Left = node*2;
    int Right = node*2 + 1;

    int mid = (b+e)/2;

    int p1 = query(Left, b, mid, i, j, carry+tree[node].prop);
    int p2 = query(Right, mid+1, e, i, j, carry+tree[node].prop);

    return p1+p2;
}

int main() {
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

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
            int l, r, toAdd;
            cin >> l >> r >> toAdd;
            update(1, 1, n, l, r, toAdd);
        }
        else if(qtype==1) {
            int l, r;
            cin >> l >> r;
            LL ret = query(1, 1, n, l, r, 0);
            cout << ret << endl;
        }
    }

    return 0;
}
