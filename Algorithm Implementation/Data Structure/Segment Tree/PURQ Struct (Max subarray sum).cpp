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
    LL arr[SIZE], Tree[4*SIZE], S[4*SIZE], L[4*SIZE], R[4*SIZE];

    inline void Init() {
        memset(arr, 0, sizeof(arr));
        memset(Tree, 0, sizeof(Tree));
        memset(S, 0, sizeof(S));
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));
    }
    inline void Build(int node = 1, int b = 1, int e = N) {
        if(b > e) return;

        if(b == e) { Tree[node] = S[node] = L[node] = R[node] = arr[b]; return; }

        int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;

        Build(left, b, mid);
        Build(right, mid+1, e);

        Tree[node] = max(Tree[left], Tree[right]);                          /// change here
        Tree[node] = max(Tree[node], R[left]+L[right]);

        L[node] = max(L[left], S[left] + L[right]);
        R[node] = max(R[right], S[right] + R[left]);

        S[node] = S[left] + S[right];
    }
    inline info Query(int i, int j, int node = 1, int b = 1, int e = N) {
        if(i > e || j < b || b > e) return info(-inf, -inf, -inf, -inf);    /// change here

        if(i <= b && j >= e) return info(Tree[node], S[node], L[node], R[node]);

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
