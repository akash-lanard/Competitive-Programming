#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> compute_hash(string const& s) {
    const int p[2] = {31, 37};
    const int m[2] = {(int)1e9+7, (int)1e9+9};
    long long hash_value[2] = {0, 0};
    long long p_pow[2] = {1, 1};

    for(int i=0; i<s.size(); i++) {
        hash_value[0] = (hash_value[0] + (s[i] - 'a' + 1) * p_pow[0]) % m[0];
        hash_value[1] = (hash_value[1] + (s[i] - 'a' + 1) * p_pow[1]) % m[1];

        p_pow[0] = (p_pow[0] * p[0]) % m[0];
        p_pow[1] = (p_pow[1] * p[1]) % m[1];
    }
    return pair<long long, long long>(hash_value[0], hash_value[1]);
}

long long getHash(string &s) {
    long long mod1 = (long long) 1e9 + 97, mod2 = (long long) 1e9 + 9;
    long long multiplier1 = 43, multiplier2 = 31;
    long long hash1 = 0, hash2 = 0;
    int n = s.size();
    long long p1 = 1, p2 = 1;
    for(int i=0; i<n; i++) {
        hash1 = (hash1 + s[i] * p1)%mod1;
        hash2 = (hash2 + s[i] * p2)%mod2;
        p1 = (p1 * multiplier1) % mod1;
        p2 = (p2 * multiplier2) % mod2;
    }
    return (hash1 << 31) | hash2;
}

int main()
{
    string str;
    cin >> str;

    pair<long long, long long> ret = compute_hash(str);

    cout << ret.first << " " << ret.second << endl;

    cout << getHash(str) << endl;

    return 0;
}
