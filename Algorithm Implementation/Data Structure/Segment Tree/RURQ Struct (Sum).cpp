/**
 Sum Query
 Range add value Update & Range sum Query
 */

#define SIZE 100005

int N, Q;

struct SEGMENT_TREE {
    int arr[SIZE], Tree[4*SIZE], Lazy[4*SIZE];

    inline void Init() {
        memset(Tree, 0, sizeof(Tree));
        memset(Lazy, 0, sizeof(Lazy));
    }
    inline void LazyPropagate(int node, int b, int e) {
        if(Lazy[node] != 0) {
            Tree[node] += (Lazy[node] * (e-b+1));       /// change here
            if(b != e) {
                Lazy[2*node] += Lazy[node];             /// change here
                Lazy[2*node + 1] += Lazy[node];         /// change here
            }
            Lazy[node] = 0;
        }
    }
    inline void Build(int node = 1, int b = 1, int e = N) {
        if(b > e) return;
        if(b == e) { Tree[node] = arr[b]; return; }
        int left = node << 1, right = left | 1, mid = (b+e) >> 1;
        Build(left, b, mid);
        Build(right, mid+1, e);
        Tree[node] = Tree[left] + Tree[right];          /// change here
    }
    inline void Update(int i, int j, int val, int node = 1, int b = 1, int e = N) {
        LazyPropagate(node, b, e);
        if(i > e || j < b || b > e) return;
        if(i <= b && j >= e) {
            Lazy[node] = val;
            LazyPropagate(node, b, e);
            return;
        }
        int left = node << 1, right = left | 1, mid = (b+e) >> 1;
        Update(i, j, val, left, b, mid);
        Update(i, j, val, right, mid + 1, e);
        Tree[node] = Tree[left] + Tree[right];          /// change here
    }
    inline int Query(int i, int j, int node = 1, int b = 1, int e = N) {
        LazyPropagate(node, b, e);
        if(i > e || j < b || b > e) return 0;           /// change here
        if(i <= b && j >= e) return Tree[node];
        int left = node << 1, right = left | 1, mid = (b+e) >> 1;
        int Q1 = Query(i, j, left, b, mid);
        int Q2 = Query(i, j, right, mid+1, e);
        return (Q1 + Q2);                               /// change here
    }

} ST;
