#include <bits/stdc++.h>
using namespace std;

#define SIZE 15

int parent[SIZE];

int flag;

int cnt;
double sum;

struct edge {
    int u, v;
    double w;

    edge() { }

    edge(int a, int b, double c)
    {
        u = a;
        v = b;
        w = c;
    }
    bool operator<(const edge& p) const
    {
        return w < p.w;
    }
};

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
    sort(edgeVec.begin(), edgeVec.end());

    init_disjoint_set(SIZE);

    cnt = 0;
    sum = 0.0;

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

int main () {
    /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */

    edgeVec.push_back(edge(0, 1, 2));
    edgeVec.push_back(edge(1, 0, 2));
    edgeVec.push_back(edge(0, 3, 6));
    edgeVec.push_back(edge(3, 0, 6));
    edgeVec.push_back(edge(1, 3, 8));
    edgeVec.push_back(edge(3, 1, 8));
    edgeVec.push_back(edge(1, 2, 3));
    edgeVec.push_back(edge(2, 1, 3));
    edgeVec.push_back(edge(1, 4, 5));
    edgeVec.push_back(edge(4, 1, 5));
    edgeVec.push_back(edge(2, 4, 7));
    edgeVec.push_back(edge(4, 2, 7));
    edgeVec.push_back(edge(3, 4, 9));
    edgeVec.push_back(edge(4, 3, 9));

    mst(5);

    cout << sum << endl;

    return 0;
}
