string toString(int n) {
    string ret = "";
    while(n>0) {
        int rem = n%10;
        ret += (char)(rem + '0');
        n /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int toNum(string str) {
    int curr = 0;
    for(int i=0; i<str.size(); i++) {
        int dig = (int)(str[i] - '0');
        curr *= 10;
        curr += dig;
    }
    return curr;
}
