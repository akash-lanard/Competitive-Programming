#define SIZE 50005

LL N, Q;

struct info {
    LL best = -inf, sum = -inf, left = -inf, right = -inf;
    info() {}
    info(LL b, LL s, LL l, LL r) {
        best = b;
        sum = s;
        left = l;
        right = r;
    }
};

struct SegmentTree {
    LL arr[SIZE];
    info Tree[4*SIZE];

    inline void Init() {
        memset(arr, 0, sizeof(arr));
        memset(Tree, 0, sizeof(Tree));
    }
    inline void Build(int node = 1, int b = 1, int e = N) {
        if(b > e) return;

        if(b == e) { Tree[node] = info(arr[b], arr[b], arr[b], arr[b]); return; }

        int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;

        Build(left, b, mid);
        Build(right, mid+1, e);

        Tree[node].best = max(Tree[left].best, Tree[right].best);                          /// change here
        Tree[node].best = max(Tree[node].best, Tree[left].right+Tree[right].left);

        Tree[node].left = max(Tree[left].left, Tree[left].sum + Tree[right].left);
        Tree[node].right = max(Tree[right].right, Tree[right].sum + Tree[left].right);

        Tree[node].sum = Tree[left].sum + Tree[right].sum;
    }
    inline info Query(int i, int j, int node = 1, int b = 1, int e = N) {
        if(i > e || j < b || b > e) return info(-inf, -inf, -inf, -inf);    /// change here

        if(i <= b && j >= e) return Tree[node];

        int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;

        info Q1 = Query(i, j, left, b, mid);
        info Q2 = Query(i, j, right, mid+1, e);

        LL currRet, currSum, currLeft, currRight;
        currRet = max(Q1.best, Q2.best);
        currRet = max(currRet, Q1.right + Q2.left);

        currLeft = max(Q1.left, Q1.sum + Q2.left);
        currRight = max(Q2.right, Q2.sum + Q1.right);

        currSum = Q1.sum + Q2.sum;

        return info(currRet, currSum, currLeft, currRight);                 /// change here
    }
} ST;
