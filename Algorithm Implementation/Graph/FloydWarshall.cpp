#include <bits/stdc++.h>
using namespace std;

#define SIZE 105

#define BIG 100000000000000

int n;

long long matrix[SIZE][SIZE];
int next[SIZE][SIZE];

void FloydWarshall() {
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

vector<int> FindPath(int i, int j) {
    vector<int> path;

    path.push_back(i);

    while(i!=j) {
        i = next[i][j];
        path.push_back(i);
    }

    return path;
}

void clr() {
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

int main() {
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

