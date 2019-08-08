#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define SIZE 505

int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

bool freivald(int n) {
    bool R[n+5];
    for(int i=0; i<n; i++) {
        R[i] = rng()%2;
    }

    int BR[n+5] = { 0 };          // compute B*r for evaluating
    for(int i=0; i<n; i++) {    // expression A * (B*r) - (C*r)
        for(int j=0; j<n; j++) {
            BR[i] = BR[i] + B[i][j] * R[j];
        }
    }

    int CR[n+5] = { 0 };          //compute C*r for evaluating
    for(int i=0; i<n; i++) {    //expression A * (B*r) - (C*r)
        for(int j=0; j<n; j++) {
            CR[i] = CR[i] + C[i][j] * R[j];
        }
    }

    int ABR[n+5] = { 0 };
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            ABR[i] = ABR[i] + A[i][j] * BR[j];
        }
    }

    for(int i=0; i<n; i++) {
        if(ABR[i]-CR[i]!=0) {
            return false;
        }
    }

    return true;
}

bool isProduct(int n, int k) {
    for(int i=0; i<k; i++) {
        if(!freivald(n)) return false;
    }
    return true;
}

int main()
{
    A[0][0] = 1;
    A[0][1] = 1;
    A[1][0] = 1;
    A[1][1] = 1;

    B[0][0] = 1;
    B[0][1] = 1;
    B[1][0] = 1;
    B[1][1] = 1;

    C[0][0] = 2;
    C[0][1] = 2;
    C[1][0] = 2;
    C[1][1] = 2;

    if(isProduct(2, 5)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}
