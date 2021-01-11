#define SIZE 30005

int N, Q;

struct SegmentTree {
    int arr[SIZE];
    vector<int> Tree[4*SIZE];

    inline void Init() {
        for(int i=0; i<4*SIZE; i++) Tree[i].clear();
    }
    inline void Build(int node = 1, int b = 1, int e = N) {
        if(b > e) return;
        if(b == e) { Tree[node].push_back(arr[b]); return; }
        int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
        Build(left, b, mid);
        Build(right, mid+1, e);
        merge(Tree[left].begin(), Tree[left].end(), Tree[right].begin(), Tree[right].end(), back_inserter(Tree[node]));
    }
    inline int Query(int i, int j, int val, int node = 1, int b = 1, int e = N) { /// Number of elements greater than val
        if(i > e || j < b || b > e) return 0;
        if(i <= b && j >= e) return (e-b+1) - (upper_bound(Tree[node].begin(), Tree[node].end(), val) - Tree[node].begin()); /// Change here
        int left = node << 1 , right = left | 1 , mid = (b+e) >> 1;
        int Q1 = Query(i, j, val, left, b, mid);
        int Q2 = Query(i, j, val, right, mid+1, e);
        return (Q1 + Q2);     /// Change here
    }
} ST;
