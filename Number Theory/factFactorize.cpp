map<int, int> factFactorize (int n) {
    map<int, int> retMap;

    for (int i = 0; i < Prime.size() && Prime[i] <= n; i++) {
        int x = n;
        int freq = 0;

        while(x / Prime[i]) {
            freq += x / Prime[i];
            x = x / Prime[i];
        }

        retMap[Prime[i]] = freq;
    }

    return retMap;
}
