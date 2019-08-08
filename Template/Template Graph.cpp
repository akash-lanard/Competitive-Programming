#include <bits/stdc++.h>
using namespace std;

///............................BFS.................................

#define SIZE 1005
#define BIG 100000000

vector<int> G[SIZE];
int level[SIZE];

void BFS(int source)
{
    queue<int> Q;
    for(int i=0; i<SIZE; i++) level[i] = BIG;

    Q.push(source);
    level[source] = 0;

    while(Q.size()!=0) {
        int u = Q.front();
        Q.pop();

        for(int v = 0; v<G[u].size(); v++) {
            if(level[G[u][v]] == BIG) {
                level[G[u][v]] = level[u] + 1;
                Q.push(G[u][v]);
            }
        }
    }
    return;
}

void clr()
{
    for(int i=0; i<SIZE; i++) G[i].clear();
}

int main()
{
    G[1].push_back(2); G[1].push_back(4); G[1].push_back(3); G[2].push_back(1);
    G[2].push_back(6); G[3].push_back(1); G[3].push_back(8); G[3].push_back(7);
    G[4].push_back(1); G[4].push_back(7); G[5].push_back(8); G[5].push_back(10);
    G[6].push_back(2); G[6].push_back(10); G[7].push_back(3); G[7].push_back(4);
    G[7].push_back(8); G[7].push_back(9); G[8].push_back(3); G[8].push_back(5);
    G[8].push_back(7); G[9].push_back(7); G[9].push_back(10); G[10].push_back(5);
    G[10].push_back(6); G[10].push_back(9);

    BFS(1);

    cout << level[5] << endl;

    return 0;
}

///........................................................................

///............................BFS2dGrid...................................

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

int cell[100][100];

int d[100][100], vis[100][100];

int row, col; //input row and col

void BFS2D(int sx, int sy)
{
    memset(vis, 0, sizeof(vis));
    vis[sx][sy] = 1;

    memset(d, 0, sizeof(d));

    queue<pair<int, int> > q;
    q.push(pair<int, int>(sx, sy));

    while(!q.empty()) {
        pair<int, int> top = q.front();
        q.pop();
        for(int k=0; k<4; k++) {
            int tx = top.first + fx[k];
            int ty = top.second + fy[k];
            if(tx>=0 && tx<row && ty>=0 && ty<col && cell[tx][ty]!=-1 && vis[tx][ty]==0) {
                vis[tx][ty] = 1;
                d[tx][ty] = d[top.first][top.second] + 1;
                q.push(pair<int, int>(tx, ty));
            }
        }
    }

}

void clr()
{
    memset(cell, 0, sizeof(cell));
}

int main()
{
    row = 8;
    col = 8;

    clr();

    cell[0][1] = -1;
    cell[1][1] = -1;

    bfs(0, 0);

    cout << d[0][2] << endl;

    return 0;
}

///................................................................................


///....................................Bicoloring..................................

#define SIZE 2005

int color[SIZE];

vector<int> G[SIZE];

vector<pair<int, int> > myvec;

int color1cnt, color2cnt;

bool Bicoloring(int source)
{
    queue<int> Q;
    Q.push(source);

    color1cnt = 0;
    color2cnt = 0;

    color[source] = 1;
    color1cnt++;

    while(Q.size()!=0) {
        int u = Q.front();
        Q.pop();

        for(int v=0; v<G[u].size(); v++) {
            int curr = G[u][v];
            if(color[curr]==0) {
                if(color[u]==1) {
                    color[curr] = 2;
                    color2cnt++;
                }
                else {
                    color[curr] = 1;
                    color1cnt++;
                }
                Q.push(curr);
            }

            if(color[u]==color[curr]) return false;
        }
    }

    myvec.push_back(pair<int, int>(color1cnt, color2cnt));
    return true;
}

void clr()
{
    for(int i=0; i<SIZE; i++) G[i].clear();
}

int main()
{
    clr();

    G[1].push_back(2);
    G[1].push_back(3);
    G[2].push_back(1);
    G[2].push_back(4);
    G[2].push_back(5);
    G[3].push_back(1);
    G[3].push_back(4);
    G[3].push_back(5);
    G[4].push_back(3);
    G[4].push_back(2);
    G[5].push_back(2);
    G[5].push_back(3);

    cout << Bicoloring(1) << endl;

    return 0;
}
///.................................................................................


///..................................DFS............................................

#define SIZE 50005

vector<int> G[SIZE];

//int visited[SIZE];

int d[SIZE], f[SIZE], color[SIZE];
int ttime;
vector<int> lst;

//int inDegree[SIZE];
//int cnt;
//int mark[SIZE];

void DFS(int source)
{
    int u = source;

    //visited[u] = 1;

    ttime++;
    d2[u] = ttime;
    color[u] = 1;

    //cnt++;
    //mark[u] = 1;

    for(int v = 0; v<G[u].size(); v++) {
        int curr = G[u][v];
        if(color[curr]==0) {
            DFS(curr);
        }
        /*if(!visited[curr]) {
            DFS(curr);
        }*/
    }

    lst.push_back(u);
    color[u] = 2;
    ttime++;
    f[u] = ttime;

    return;
}

void clr()
{
    for(int i=0; i<SIZE; i++) G[i].clear();

    //memset(visited, 0, sizeof(visited));

    memset(d, 0, sizeof(d));
    memset(f, 0, sizeof(f));
    memset(color, 0, sizeof(color));
    lst.clear();
    ttime = 0;

    //memset(inDegree, 0, sizeof(inDegree));
    //memset(mark, 0, sizeof(mark));
}

int main()
{
    clr();

    int n = 5;

    G[1].push_back(4);
    G[2].push_back(1);
    G[2].push_back(3);
    G[3].push_back(4);

    //DFS(1);
    for(int i=1; i<n; i++) {
        if(color[i]==0) DFS(i);
    }

    for(int i=1; i<n; i++) {
        printf("Node: %d, d[]: %d, f[]: %d\n", i, d[i], f[i]);
    }

    for(int i=0; i<lst.size(); i++) {
        printf("%d ", lst[i]);
    }
    printf("\n");

    return 0;
}

///.........................................................................................

///..............................Dijkstra...................................................

#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005
#define BIG 1000000000000005

long long dis[SIZE];
int pre[SIZE];

struct Node
{
    int id, dist;

    Node() {}

    Node(int id, int dist)
    {
        this->id = id;
        this->dist = dist;
    }

    bool operator < (const Node &a)const {
        return dist > a.dist;
    }
};

vector<pair<int, int> > G[SIZE];

void  dijkstra(int source)
{
    priority_queue<Node> Q;

    for(int i=0; i<SIZE; i++) {
        dis[i] = BIG;
        pre[i] = -1;
    }

    Node s(source, 0);

    Q.push(s);

    dis[source] = 0;

    //printf("BFS: %d", source);

    while(!Q.empty()) {
        Node curr = Q.top();
        Q.pop();

        int u = curr.id;
        int curr_dist = curr.dist;
        
        if(curr_dist!=dis[u]) continue;

        for(int i=0; i<G[u].size(); i++) {
            int v = G[u][i].first;
            int cost = G[u][i].second;

            if(dis[u]+cost < dis[v]) {
                dis[v] = dis[u] + cost;

                Node n(v, dis[v]);

                Q.push(n);

                pre[v] = u;

                //printf(" %d", v);
            }
        }
    }
    //printf("\n");
}

void clr()
{
    for(int i=0; i<SIZE; i++) G[i].clear();
}

int main () {
    #ifdef forthright48
    freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    //fast_cin;

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<m; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);

        G[a].push_back(pair<int, int>(b, w));
        G[b].push_back(pair<int, int>(a, w));
    }

    dijkstra(1);

    if(dis[n]==BIG) {
        printf("-1\n");
    }
    else {
        vector<int> ansVec;

        int curr = n;
        while(curr!=1) {
            ansVec.push_back(curr);
            curr = pre[curr];
        }
        ansVec.push_back(1);

        for(int i=ansVec.size()-1; i>=0; i--) {
            if(i==ansVec.size()-1) printf("%d", ansVec[i]);
            else printf(" %d", ansVec[i]);
        }
        printf("\n");
    }

    return 0;
}

///...............................................................................


///.................................Dijkstra2D....................................

#define SIZE 1005

int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

int ara[SIZE][SIZE];

int d[SIZE][SIZE];

int cell[SIZE][SIZE];

int row, col;

struct Node
{
    int id_x, id_y, dist;

    Node() {}

    Node(int id_x, int id_y, int dist)
    {
        this->id_x = id_x;
        this->id_y = id_y;
        this->dist = dist;
    }

    bool operator < (const Node &a)const {
        return dist > a.dist;
    }
};

void  dijkstra2D(int sx, int sy)
{
    priority_queue<Node> Q;

    d[sx][sy] = ara[sx][sy];

    Node s(sx, sy, d[sx][sy]);

    Q.push(s);

    //printf("BFS: %d", source);

    while(!Q.empty()) {
        Node curr = Q.top();
        Q.pop();

        int curr_x = curr.id_x;
        int curr_y = curr.id_y;
        int curr_dist = curr.dist;

        if(curr_dist != d[curr_x][curr_y]) continue;

        for(int k=0; k<4; k++) {
            int tx = curr_x + fx[k];
            int ty = curr_y + fy[k];

            if(tx>=0 && tx<row && ty>=0 && ty<col && cell[tx][ty]!=-1) {
                int cost = ara[tx][ty];

                if(curr_dist + cost < d[tx][ty]) {
                    d[tx][ty] = curr_dist + cost;

                    Node n(tx, ty, d[tx][ty]);
                    Q.push(n);
                }
            }
        }
    }
    //printf("\n");
}

void clr()
{
    memset(ara, 1, sizeof(ara));

    memset(cell, 0, sizeof(cell));

    memset(d, 1, sizeof(d));
}

int main () {
    #ifdef forthright48
    //freopen ( "input.txt", "r", stdin );
    //freopen ( "output.txt", "w", stdout );
    #endif // forthright48

    //fast_cin;

    clr();

    scanf("%d %d", &row, &col);
    for(int j=0; j<row; j++) {
        for(int k=0; k<col; k++) {
            scanf("%d", &ara[j][k]);
        }
    }

    dijkstra2D(0, 0);

    printf("d contains:\n");
    for(int j=0; j<row; j++) {
        for(int k=0; k<col; k++) {
            printf("%d ", d[j][k]);
        }
        printf("\n");
    }

    return 0;
}

///..............................................................................

///.................................MST(Kruskal's)...............................

#define SIZE 3005

int parent[SIZE];

int flag;

int cnt;
int sum;

struct edge {
    int u, v;
    int w;

    edge() { }

    edge(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
};

bool comp(const edge& a, const edge& b)
{
    if(a.w < b.w) return true;
    else return false;
}

vector<edge> edgeVec;


void makeset(int u)
{
    parent[u] = u;
}

void init_disjoint_set(int N)
{
    for(int i=0; i<N; i++) {
        makeset(i);
    }
}

/*int FindRepresentative(int r)   //without path compression
{
    if(parent[r]==r) {
        return r;
    }
    return FindRepresentative(parent[r]);
}*/

int FindRepresentative(int r)   //with path compression
{
    if(parent[r]==r) {
        return r;
    }

    parent[r] = FindRepresentative(parent[r]);

    return parent[r];
}

void Union(int a, int b)
{
    int u = FindRepresentative(a);
    int v = FindRepresentative(b);

    if(u!=v) {
        parent[u] = v;
        flag = 1;
    }
}

double mst(int n)
{
    sort(edgeVec.begin(), edgeVec.end(), comp);

    init_disjoint_set(SIZE);

    cnt = 0;
    sum = 0;

    for(int i=0; i<edgeVec.size(); i++) {
        flag = 0;
        Union(edgeVec[i].u, edgeVec[i].v);
        if(flag) {
            cnt++;
            sum += edgeVec[i].w;
            if(cnt==n-1) break;
        }
    }

    return sum;
}

void clr()
{
    edgeVec.clear();
}

int main () {
    /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */

    edgeVec.push_back(edge(0, 1, 2)); edgeVec.push_back(edge(1, 0, 2));
    edgeVec.push_back(edge(0, 3, 6)); edgeVec.push_back(edge(3, 0, 6));
    edgeVec.push_back(edge(1, 3, 8)); edgeVec.push_back(edge(3, 1, 8));
    edgeVec.push_back(edge(1, 2, 3)); edgeVec.push_back(edge(2, 1, 3));
    edgeVec.push_back(edge(1, 4, 5)); edgeVec.push_back(edge(4, 1, 5));
    edgeVec.push_back(edge(2, 4, 7)); edgeVec.push_back(edge(4, 2, 7));
    edgeVec.push_back(edge(3, 4, 9)); edgeVec.push_back(edge(4, 3, 9));

    mst(5);

    cout << sum << endl;

    return 0;
}

///.......................................................................

///..........................MST(Prim's)..................................

#define SIZE 5

vector<pair<int, int> > G[SIZE];

int parent[SIZE];
int key[SIZE];
bool mstSet[SIZE];

int minKey()
{
    int mn = INT_MAX;
    int mn_indx;

    for(int i=0; i<SIZE; i++) {
        if(mstSet[i]==false && key[i]<mn) {
            mn = key[i];
            mn_indx = i;
        }
    }

    return mn_indx;
}

int printMST()
{
    printf("Edge    Weight\n");
    for(int i=1; i<SIZE; i++) {
        printf("%d - %d   ", parent[i], i);
        int cost = -1;
        for(int j=0; j<G[parent[i]].size(); j++) {
            if(G[parent[i]][j].first==i) {
                cost = G[parent[i]][j].second;
                break;
            }
        }
        printf("%d\n", cost);
    }
}

void primMST(int s)
{
    for(int i=0; i<SIZE; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[s] = 0;
    parent[s] = -1;

    for(int cnt=0; cnt<SIZE-1; cnt++) {
        int u = minKey();

        mstSet[u] = true;

        for(int i=0; i<G[u].size(); i++) {
            int v = G[u][i].first;
            int cost = G[u][i].second;
            if(mstSet[v]==false && cost<key[v]) {
                parent[v] = u;
                key[v] = cost;
            }
        }
    }

    printMST();
}

int main()
{
   /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
    G[0].push_back(pair<int,int>(1, 2)); G[0].push_back(pair<int,int>(3, 6));
    G[1].push_back(pair<int,int>(0, 2)); G[1].push_back(pair<int,int>(3, 8));
    G[1].push_back(pair<int,int>(4, 5)); G[1].push_back(pair<int,int>(2, 3));
    G[2].push_back(pair<int,int>(1, 3)); G[2].push_back(pair<int,int>(4, 7));
    G[3].push_back(pair<int,int>(0, 6)); G[3].push_back(pair<int,int>(1, 8));
    G[3].push_back(pair<int,int>(4, 9)); G[4].push_back(pair<int,int>(2, 7));
    G[4].push_back(pair<int,int>(1, 5)); G[4].push_back(pair<int,int>(3, 9));

    // Print the solution
    primMST(0);

    return 0;
}
///..............................................................


///..........................TopSort.............................

#define SIZE 105

vector<int> G[SIZE];

vector<int> L;

queue<int> Q;

int inDegree[SIZE];

void topsort(int N)
{
    L.clear();
    while(!Q.empty()) Q.pop();

    for(int i=1; i<=N; i++) {
        if(inDegree[i]==0) {
            Q.push(i);
        }
    }

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();

        L.push_back(u);

        for(int i=0; i<G[u].size(); i++) {
            int v = G[u][i];
            inDegree[v]--;
            if(inDegree[v]==0) {
                Q.push(v);
            }
        }
    }
}

void clr()
{
    for(int i=0; i<SIZE; i++) G[i].clear();
    memset(inDegree, 0, sizeof(inDegree));
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int n, m;
    while(1) {
        scanf("%d %d", &n, &m);
        if(n==0 & m==0) break;

        clr();

        for(int i=0; i<m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            G[u].push_back(v);
            inDegree[v]++;
        }

        topsort(n);

        for(int i=0; i<L.size(); i++) {
            if(i==0) printf("%d", L[i]);
            else printf(" %d", L[i]);
        }
        printf("\n");
    }

    return 0;
}

///..............................................................


///..........................Bellman-Ford........................

#define SIZE 1005
#define BIG 1000000000000005

long long dis[SIZE];
int pre[SIZE];

int n;

vector<pair<int, int> > G[SIZE];

bool bellmanFord(int source)
{
    for(int i=0; i<SIZE; i++) {
        dis[i] = BIG;
        pre[i] = -1;
    }

    dis[source] = 0;

    for(int i=1; i<=n-1; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=0; k<G[j].size(); k++) {
                int currID = G[j][k].first;
                int currCost = G[j][k].second;

                if(dis[j] + currCost < dis[currID]) {
                    dis[currID] = dis[j] + currCost;

                    pre[currID] = j;
                }
            }
        }
    }

    for(int j=1; j<=n; j++) {
        for(int k=0; k<G[j].size(); k++) {
            int currID = G[j][k].first;
            int currCost = G[j][k].second;

            if(dis[j] + currCost < dis[currID]) {
                return false;
            }
        }
    }

    return true;
}

void clr()
{
    for(int i=0; i<SIZE; i++) G[i].clear();
}

int main()
{
    #ifdef forthright48
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // forthright48

    clr();

    int m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[u].push_back(pair<int, int>(v, w));
    }

    if(bellmanFord(1)) {
        for(int i=1; i<=n; i++) {
            if(dis[i]!=BIG) printf("dis[%d] = %lld\n", i, dis[i]);
            else printf("dis[%d] = inf\n", i);
        }

        for(int i=1; i<=n; i++) {
            printf("Path of %d:", i);
            if(dis[i]==BIG) {
                printf(" invalid\n");
            }
            else {
                vector<int> path;
                int curr = i;
                while(1) {
                    path.push_back(curr);
                    curr = pre[curr];
                    if(curr==-1) break;
                }

                for(int j=path.size()-1; j>=0; j--) {
                    printf(" %d", path[j]);
                }
                printf("\n");
            }
        }
    }
    else {
        printf("Negative cycle detected\n");
    }

    return 0;
}

///...............................................................

///....................Floyd Warshall................................

#include <bits/stdc++.h>
using namespace std;

#define SIZE 100

#define BIG 100000000000000

int n;

long long matrix[SIZE][SIZE];
int next[SIZE][SIZE];

void FloydWarshall()
{
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

vector<int> FindPath(int i, int j)
{
    vector<int> path;

    path.push_back(i);

    while(i!=j) {
        i = next[i][j];
        path.push_back(i);
    }

    return path;
}

void clr()
{
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            matrix[i][j] = BIG;
        }
    }

    for(int i=0; i<SIZE; i++) {
        matrix[i][i] = 0;
    }

    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            next[i][j] = j;
        }
    }
}

int main()
{
    #ifdef forthright48
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // forthright48

    clr();

    int m;

    scanf("%d %d", &n, &m);

    for(int i=1; i<=m; i++) {
        int u, v;
        long long w;
        scanf("%d %d %lld", &u, &v, &w);
        matrix[u][v] = w;
    }

    FloydWarshall();

    printf("Matrix:\n");
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(matrix[i][j]==BIG) printf("inf ");
            else printf("%lld ", matrix[i][j]);
        }
        printf("\n");
    }


    vector<int> path = FindPath(4, 2);

    printf("\nPath(4 to 2): ");
    for(int i=0; i<path.size(); i++) {
        printf("%d ", path[i]);
    }
    printf("\n");

    return 0;
}

///...............................................................



///.................END OF TEMPLATE...............................

