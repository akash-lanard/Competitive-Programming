#include <bits/stdc++.h>
using namespace std;

/////...............Disjoint Set (with size).......................
//#include <bits/stdc++.h>
//using namespace std;
//
//#define SIZE 150005
//
//int parent[SIZE];
//int sz[SIZE];
//
//void makeset(int u) {
//    parent[u] = u;
//    sz[u] = 1;
//}
//
//void init_disjoint_set(int N) {
//    for(int i=0; i<=N; i++) {
//        makeset(i);
//    }
//}
//
//int FindRepresentative(int r) {  //with path compression
//    if(parent[r]==r) {
//        return r;
//    }
//
//    parent[r] = FindRepresentative(parent[r]);
//
//    return parent[r];
//}
//
//int FindSize(int r) {
//    return sz[FindRepresentative(r)];
//}
//
//void Union(int a, int b) {
//    int u = FindRepresentative(a);
//    int v = FindRepresentative(b);
//
//    if(u!=v) {
//        parent[u] = v;
//        sz[v] += sz[u];
//    }
//}
//
//int main () {
//    #ifdef forthright48
//    freopen ( "input.txt", "r", stdin );
//    //freopen ( "output.txt", "w", stdout );
//    #endif // forthright48
//
//    //fast_cin;
//
//    init_disjoint_set(10);
//
//    Union(1, 2);
//    Union(1, 3);
//
//    Union(4, 5);
//
//    Union(2, 5);
//
//    cout << FindSize(5) << endl;
//
//    return 0;
//}
/////...................................
//
/////.......................Segment tree (shafaetblog)................
//#include <bits/stdc++.h>
//using namespace std;
//
//#define SIZE 100002
//
//int arr[SIZE];
//int tree[SIZE*4];
//
//void init(int node, int b, int e) {
//    if(b==e) {
//        tree[node] = arr[b];
//        return;
//    }
//
//    int Left = node*2;
//    int Right = node*2 + 1;
//
//    int mid = (b+e) / 2;
//
//    init(Left, b, mid);
//    init(Right, mid+1, e);
//
//    tree[node] = tree[Left] + tree[Right];
//}
//
//int query(int node, int b, int e, int i, int j) {
//    if(e<i || j<b) {
//        return 0;
//    }
//    if(i<=b && e<=j) {
//        return tree[node];
//    }
//
//    int Left = node*2;
//    int Right = node*2 + 1;
//
//    int mid = (b+e)/2;
//
//    int p1 = query(Left, b, mid, i, j);
//    int p2 = query(Right, mid+1, e, i, j);
//
//    return p1+p2;
//}
//
//void update(int node, int b, int e, int i, int newVal) {
//    if(e<i || i<b) {
//        return;
//    }
//    if(i<=b && e<=i) {
//        tree[node] = newVal;
//        return;
//    }
//
//    int Left = node*2;
//    int Right = node*2 + 1;
//
//    int mid = (b+e)/2;
//
//    update(Left, b, mid, i, newVal);
//    update(Right, mid+1, e, i, newVal);
//
//    tree[node] = tree[Left] + tree[Right];
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//    for(int i=1; i<=n; i++) {
//        cin >> arr[i];
//    }
//
//    init(1, 1, n);
//
//    int q;
//    cin >> q;
//    for(int i=1; i<=q; i++) {
//        int qtype;
//        cin >> qtype;
//        if(qtype==0) {
//            int indx, newVal;
//            cin >> indx >> newVal;
//            update(1, 1, n, indx, newVal);
//        }
//        else if(qtype==1) {
//            int l, r;
//            cin >> l >> r;
//            int ret = query(1, 1, n, l, r);
//            cout << ret << "\n";
//        }
//    }
//
//    return 0;
//}
/////..........................................................
//
/////....................Segment tree lazy propagation (shafaetblog)...............
//#include <bits/stdc++.h>
//using namespace std;
//
//#define LL long long
//
//#define SIZE 100002
//
//int arr[SIZE];
//
//struct info {
//    LL prop, sum;
//} tree[SIZE*4];
//
//void init(int node, int b, int e) {
//    if(b==e) {
//        tree[node].sum = arr[b];
//        return;
//    }
//
//    int Left = node*2;
//    int Right = node*2 + 1;
//
//    int mid = (b+e) / 2;
//
//    init(Left, b, mid);
//    init(Right, mid+1, e);
//
//    tree[node].sum = tree[Left].sum + tree[Right].sum;
//}
//
//void update(int node, int b, int e, int i, int j, LL x) {
//    if(e<i || j<b) {
//        return;
//    }
//    if(i<=b && e<=j) {
//        tree[node].sum += ((e-b+1)*x);
//        tree[node].prop += x;
//        return;
//    }
//
//    int Left = node*2;
//    int Right = node*2 + 1;
//
//    int mid = (b+e)/2;
//
//    update(Left, b, mid, i, j, x);
//    update(Right, mid+1, e, i, j, x);
//
//    tree[node].sum = tree[Left].sum + tree[Right].sum + ((e-b+1)*tree[node].prop);
//}
//
//LL query(int node, int b, int e, int i, int j, LL carry=0) {
//    if(e<i || j<b) {
//        return 0;
//    }
//    if(i<=b && e<=j) {
//        return tree[node].sum + carry*(e-b+1);
//    }
//
//    int Left = node*2;
//    int Right = node*2 + 1;
//
//    int mid = (b+e)/2;
//
//    int p1 = query(Left, b, mid, i, j, carry+tree[node].prop);
//    int p2 = query(Right, mid+1, e, i, j, carry+tree[node].prop);
//
//    return p1+p2;
//}
//
//int main() {
//    #ifdef forthright48
//    freopen ( "input.txt", "r", stdin );
//    //freopen ( "output.txt", "w", stdout );
//    #endif // forthright48
//
//    int n;
//    cin >> n;
//    for(int i=1; i<=n; i++) {
//        cin >> arr[i];
//    }
//
//    init(1, 1, n);
//
//    int q;
//    cin >> q;
//    for(int i=1; i<=q; i++) {
//        int qtype;
//        cin >> qtype;
//        if(qtype==0) {
//            int l, r, toAdd;
//            cin >> l >> r >> toAdd;
//            update(1, 1, n, l, r, toAdd);
//        }
//        else if(qtype==1) {
//            int l, r;
//            cin >> l >> r;
//            LL ret = query(1, 1, n, l, r, 0);
//            cout << ret << endl;
//        }
//    }
//
//    return 0;
//}
/////.....................................................
//
/////......................Dynamic Segment Tree.....................
//#include <bits/stdc++.h>
//using namespace std;
//
//typedef long long int LL;
//const int N = 1e5 + 5;
//
///**
// Dynamic/sparse Segtree (with lazy propagation )
// array : 1 based indexed
// operations :
// type 1 -> update : add val in L to R
// type 2 -> query : qum of elements in L to R
// */
//struct Node {
//        Node *l , *r;
//        LL sum;
//        LL lazy;
//        Node ( ) {
//                l = NULL , r = NULL , sum = 0 , lazy = 0;
//        }
//        Node( LL b , LL e ) {
//                l = NULL , r = NULL , sum = 0 , lazy = 0;
//        }
//        void Merge( int b , int e ) {
//                sum = 0;
//                int mid = ( b + e ) >> 1;
//                if( l ) sum += l -> sum;
//                if( r ) sum += r -> sum;
//        }
//} *root;
//
//typedef Node* pNode;
//
//int n , q;
//LL a[ N ];
//
//void Propagate( pNode &cur , int b , int e ) {
//        if( cur -> lazy == 0 ) return;
//        int mid = ( b + e ) >> 1;
//        if( !( cur -> l ) ) cur -> l = new Node();
//        if( !( cur -> r ) ) cur -> r = new Node();
//        cur -> l -> sum += ( cur -> lazy * ( mid - b + 1 ) );
//        cur -> r -> sum += ( cur -> lazy * ( e - mid ) );
//        cur -> l -> lazy += cur -> lazy;
//        cur -> r -> lazy += cur -> lazy;
//        cur -> lazy = 0;
//}
//void Build( pNode &cur , int b , int e ) {
//        if( b > e ) return;
//        if( !cur ) cur = new Node();
//        if( b == e ) {
//                cur -> sum = a[b];
//                return;
//        }
//        int m = ( b + e ) >> 1;
//        Build( cur -> l , b , m );
//        Build( cur -> r , m + 1 , e );
//        cur -> Merge( b , e );
//}
//void Update( pNode &cur , int b , int e , int i , int j , int val ) {
//        if( i > e || j < b || b > e ) return;
//        if( !cur ) cur = new Node();
//        if( i <= b && j >= e ) {
//                cur -> sum += ( 1LL * val * ( e - b + 1 ) );
//                cur -> lazy += val;
//                return;
//        }
//        Propagate( cur , b , e );
//        int mid = ( b + e ) >> 1;
//        Update( cur -> l , b , mid , i , j , val );
//        Update( cur -> r , mid + 1 , e , i , j , val );
//        cur -> Merge( b , e );
//}
//LL Query( pNode &cur , int b , int e , int i , int j ) {
//        if( i > e || j < b || b > e ) return 0;
//        if( !cur ) cur = new Node();
//        if( i <= b && j >= e ) return cur -> sum;
//        Propagate( cur , b , e );
//        int mid = ( b + e ) >> 1;
//        LL x = Query( cur -> l , b , mid , i , j );
//        LL y = Query( cur -> r , mid + 1 , e , i , j );
//        return ( x + y );
//}
//int main( int argc , char const *argv[] ) {
//        ios_base::sync_with_stdio( false ); cin.tie( NULL );
//        root = NULL;
//        cin >> n >> q;
//        for( int i = 1; i <= n; i++ ) cin >> a[i];
//        Build( root , 1 , n );
//        for( int i = 1; i <= q; i++ ) {
//                int type;
//                cin >> type;
//                if( type == 1 ) { ///range update
//                        int l , r , val;
//                        cin >> l >> r >> val;
//                        Update( root , 1 , n , l , r , val );
//                }
//                else { /// range sum query
//                        int l , r;
//                        cin >> l >> r;
//                        cout << Query( root , 1 , n , l , r ) << endl;
//                }
//        }
//        return 0;
//}
/////................................................................
//
/////...................Trie-Array......................
//#include <bits/stdc++.h>
//using namespace std;
//
//#define SIZE 100000
//
///// Trie Array Based Implementation
///// Call insert() to insert new string
///// Call search() to search a string
//
//struct node {
//    int cnt; /// Change here if you need
//    int child[55];
//};
//
//node T[SIZE];
//
//struct Trie {
//    int id;
//
//    void createNode() {
//        T[id].cnt = 0;
//        memset(T[id].child, -1, sizeof(T[id].child));
//        id++;
//    }
//
//    void clear() {
//        id = 0;
//        createNode();
//    }
//
//    /// Returns the corresponding integer id of the character
//    int FID(const char &c) {
//        if(c>='A' && c<='Z') return c - 'A';
//        else return (c - 'a') + 26;
//    }
//
//    void insert(string &s) {
//        int cur = 0;
//        T[cur].cnt++;
//        for(int i=0; i<s.size(); i++) {
//            int p = FID(s[i]);
//            if(T[cur].child[p]==-1) {
//                T[cur].child[p] = id;
//                createNode();
//            }
//            cur = T[cur].child[p];
//            T[cur].cnt++;
//        }
//    }
//
//    /// Returns number of occurance of s.
//    int search(string &s) {
//        int cur = 0;
//        for(int i=0; i<s.size(); i++) {
//            int p = FID(s[i]);
//            if(T[cur].child[p]==-1) return 0;
//            cur = T[cur].child[p];
//        }
//        return T[cur].cnt;
//    }
//}root;
//
//int main()
//{
//    string keys[] = {"the", "a", "there",
//                    "answer", "any", "by",
//                     "bye", "their" };
//
//    root.clear();
//
//    for(int i=0; i<8; i++) {
//        root.insert(keys[i]);
//    }
//
//    string str1 = "the", str2 = "these";
//
//    cout << root.search(str1) << endl; /// prints 3
//    cout << root.search(str2) << endl; /// prints 0
//
//    return 0;
//}
/////......................................................
//
/////..................Trie-Recursive...........................
//#include <bits/stdc++.h>
//using namespace std;
//
///// Trie Recursion based implementation
///// Create the root (root = new Trie())
///// Use insert and search accordingly
///// At the end call delete_trie() to delete all the nodes
///// Done for only digits by default
//
//#define SIZE 10
//
//class Trie {
//    bool ed;
//    Trie *child[SIZE];
//    /// If ed is true, a word is finished here
//
//public:
//    Trie() {
//        ed = false;
//        for(int i=0; i<SIZE; i++) {
//            child[i] = NULL;
//        }
//    }
//
//    /// Delete to save memory
//    void delete_trie() {
//        for(int i=0; i<SIZE; i++) {
//            if(child[i]!=NULL) {
//                child[i]->delete_trie();
//                delete child[i];
//            }
//        }
//    }
//
//    void insert(string &word, int pos) {
//        if(pos==(int)word.length()) {
//            ed = true;
//            return;
//        }
//        int c = (int)(word[pos] - '0'); ///change here
//        if(child[c] == NULL) {
//            child[c] = new Trie();
//        }
//        return child[c]->insert(word, ++pos);
//    }
//
//    bool search(string &word, int pos) {
//        if(pos==(int)word.length()) return ed;
//        int c = (int)(word[pos] - '0');
//        if(child[c]==NULL) return false;
//        return child[c]->search(word, ++pos);
//    }
//}*root;
//
//
//
//int main()
//{
//    string keys[] = {"1", "12", "23", "26", "203", "07", "8", "077"};
//
//    root = new Trie();
//
//    for(int i=0; i<8; i++) {
//        root->insert(keys[i], 0);
//    }
//
//    string str1 = "07", str2 = "0";
//
//    cout << root->search(str1, 0) << endl; /// prints 1
//    cout << root->search(str2, 0) << endl; /// prints 0
//
//    return 0;
//}
/////.................................................................
int main () {
    #ifdef forthright48
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    //fast_cin;

    int n;
    cin >> n;
    cout << n << endl;

    return 0;

    return 0;
}

