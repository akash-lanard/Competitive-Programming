#include <bits/stdc++.h>
using namespace std;

#define SIZE 105

int parent[SIZE];

void makeset(int u)
{
    parent[u] = u;
}

void init_disjoint_set(int N)
{
    for(int i=0; i<=N; i++) {
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
    }
}

int main()
{
    #ifdef forthright48
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // forthright48

    int n, m;
    scanf("%d %d", &n, &m);

    init_disjoint_set(n);

    for(int i=0; i<m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        Union(u, v);
    }

    int q;
    scanf("%d", &q);
    for(int i=0; i<q; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        int x = FindRepresentative(u);
        int y = FindRepresentative(v);

        if(x==y) {
            printf("%d and %d are from the same set\n", u, v);
            printf("Representative(%d) = %d, Representative(%d) = %d\n\n", u, x, v, y);
        }
        else {
            printf("%d and %d are from the different sets\n", u, v);
            printf("Representative(%d) = %d, Representative(%d) = %d\n\n", u, x, v, y);
        }
    }

    return 0;
}
