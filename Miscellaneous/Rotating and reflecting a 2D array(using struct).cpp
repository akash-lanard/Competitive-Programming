/*
ID: akashla1
TASK: transform
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define SIZE 15

struct board {
    int n;
    int ara[SIZE][SIZE];
};

board readBoard(int n) {
    board b;

    b.n = n;

    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            b.ara[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;

        for(int j=0; j<n; j++) {
            if(str[j]=='@') {
                b.ara[i][j] = 1;
            }
        }
    }

    return b;
}

bool isEqual(board a, board b) {
    if(a.n != b.n) return false;

    for(int i=0; i<a.n; i++) {
        for(int j=0; j<a.n; j++) {
            if(a.ara[i][j] != b.ara[i][j]) return false;
        }
    }

    return true;
}

board rotate90(board b) {
    board ret;

    ret.n = b.n;

    for(int i=0; i<b.n; i++) {
        for(int j=0; j<b.n; j++) {
            ret.ara[i][j] = b.ara[b.n-j-1][i];
        }
    }

    return ret;
}

board reflect(board b) {
    board ret;

    ret.n = b.n;

    for(int i=0; i<b.n; i++) {
        for(int j=0; j<b.n; j++) {
            ret.ara[i][j] = b.ara[i][b.n-j-1];
        }
    }

    return ret;
}

int main() {
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);

    int N;
    cin >> N;

    board initBoard = readBoard(N);

    board finalBoard = readBoard(N);

    if(isEqual(finalBoard, rotate90(initBoard))) {
        cout << "1\n";
    }
    else if(isEqual(finalBoard, rotate90(rotate90(initBoard)))) {
        cout << "2\n";
    }
    else if(isEqual(finalBoard, rotate90(rotate90(rotate90(initBoard))))) {
        cout << "3\n";
    }
    else if(isEqual(finalBoard, reflect(initBoard))) {
        cout << "4\n";
    }
    else if(isEqual(finalBoard, rotate90(reflect(initBoard)))) {
        cout << "5\n";
    }
    else if(isEqual(finalBoard, rotate90(rotate90(reflect(initBoard))))) {
        cout << "5\n";
    }
    else if(isEqual(finalBoard, rotate90(rotate90(rotate90(reflect(initBoard)))))) {
        cout << "5\n";
    }
    else if(isEqual(finalBoard, initBoard)) {
        cout << "6\n";
    }
    else {
        cout << "7\n";
    }

    return 0;
}
