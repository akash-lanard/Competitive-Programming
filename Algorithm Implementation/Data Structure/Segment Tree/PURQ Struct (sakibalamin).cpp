/**
 Sum Query
 Point Update & Range Query
 */

#define SIZE 100005

int N, Q;

struct SegmentTree {
    int arr[SIZE], Tree[4*SIZE];

    inline void Init() {
        memset(Tree, 0, sizeof(Tree));
    }
    inline void Build(int node = 1, int b = 1, int e = N) {
        if(b > e) return;
        if(b == e) { Tree[node] = arr[b]; return; }
        int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
        Build(left, b, mid);
        Build(right, mid+1, e);
        Tree[node] = Tree[left] + Tree[right];
    }
    inline void Update(int pos, int val, int node = 1, int b = 1, int e = N) {
        if(pos > e || pos < b || b > e) return;
        if(b == e && b == pos) { Tree[node] = arr[b] = val; return; }
        int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
        Update(pos, val, left, b, mid);
        Update(pos, val, right, mid+1, e);
        Tree[node] = Tree[left] + Tree[right];
    }
    inline int Query(int i, int j, int node = 1, int b = 1, int e = N) {
        if(i > e || j < b || b > e) return 0;
        if(i <= b && j >= e) return Tree[node];
        int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
        int Q1 = Query(i, j, left, b, mid);
        int Q2 = Query(i, j, right, mid+1, e);
        return (Q1 + Q2);
    }
} ST;
