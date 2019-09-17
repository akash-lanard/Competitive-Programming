/// Reference: https://www.geeksforgeeks.org/c-program-multiply-two-matrices/

#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000           /// adjust SIZE if needed

int m1, m2;                 /// dimension of first matrix m1 X m2
int n1, n2;                 /// dimension of second matrix n1 X n2
                            /// Note: m2 must be equal to n1

int mat1[SIZE][SIZE];       /// first matrix
int mat2[SIZE][SIZE];       /// second matrix
int res[SIZE][SIZE];        /// resultant matrix (dimension m1 X n2)

void multiply() {
    for(int i=0; i<m1; i++) {       /// row of resultant matrix
        for(int j=0; j<n2; j++) {   /// column of resultant matrix
            res[i][j] = 0;
            for(int k=0; k<m2; k++) {   /// m2==n1
                res[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }
}

int main() {
    cin >> m1 >> m2;
    for(int i=0; i<m1; i++) {
        for(int j=0; j<m2; j++) {
            cin >> mat1[i][j];
        }
    }

    cin >> n1 >> n2;
    for(int i=0; i<n1; i++) {
        for(int j=0; j<n2; j++) {
            cin >> mat2[i][j];
        }
    }

    multiply();

    cout << "resultant matrix is:\n";
    for(int i=0; i<m1; i++) {
        for(int j=0; j<n2; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
