#include <bits/stdc++.h>
using namespace std;

struct Hashing {
    long long *hash1, *hash2;
    long long *inv1, *inv2;
    int n;
    long long mod1 = (long long) 1e9 + 97, mod2 = (long long) 1e9 + 9;
    long long multiplier1 = 43, multiplier2 = 31;
    long long invMultiplier1 = 441860508, invMultiplier2 = 838709685;
    // invMultiplier = modInv(multiplier, mod) //

    Hashing() {

    }

    Hashing(string &s) {
        build_Hash(s);
    }

    void build_Hash(string &s) {
        n = s.size();
        hash1 = new long long[n + 1];
        hash2 = new long long[n + 1];
        inv1 = new long long[n + 1];
        inv2 = new long long[n + 1];

        hash1[0] = hash2[0] = 0;
        inv1[0] = inv2[0] = 1;

        long long p1 = 1, p2 = 1;

        for (int i = 0; i < n; i++) {
            hash1[i + 1] = (hash1[i] + s[i] * p1) % mod1;
            p1 = (p1 * multiplier1) % mod1;
            inv1[i + 1] = inv1[i] * invMultiplier1 % mod1;
            hash2[i + 1] = (hash2[i] + s[i] * p2) % mod2;
            p2 = (p2 * multiplier2) % mod2;
            inv2[i + 1] = inv2[i] * invMultiplier2 % mod2;
        }
    }


    long long getHash(int i, int j) { //0-based, hash of substring [i, j]
        return getHash_2(i, j - i + 1);
    }

    long long getHash_2(int i, int len) { //0- based, hash of substring [i, i+len-1]
        return (((hash1[i + len] - hash1[i] + mod1) * inv1[i] % mod1) << 32)
               + (hash2[i + len] - hash2[i] + mod2) * inv2[i] % mod2;
    }

    long long revHash(int i, int j) { //0-based
        return getHash(n - j - 1, n - i - 1);
    }

    void clear() {
        delete (hash1);
        delete (hash2);
        delete (inv1);
        delete (inv2);
    }
};


Hashing hashing;

int main () {
    string str;
    cin >> str;

    hashing.build_Hash(str);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        long long h = hashing.getHash(a, b);
        long long r = hashing.revHash(a, b);
        cout << "Hash = " << h << ", revHash = " << r << endl;
    }

    return 0;
}
