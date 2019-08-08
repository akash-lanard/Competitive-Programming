#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int Mod[2] = { 1000000007, 1000000009 };
const int Base[2] = { 37, 31 };


LL getHash(string s) {
    LL Hash1 = 0, Hash2 = 0;
    int len = s.size();
    for(int i=1; i<=len; i++) {
        Hash1 = (Hash1 * Base[0] + s[i-1]) % Mod[0];
        Hash2 = (Hash2 * Base[1] + s[i-1]) % Mod[1];
    }
    return (Hash1 << 31) | Hash2;
}

int main() {
    string str;
    cin >> str;
    cout << getHash(str) << endl;
    return 0;
}
