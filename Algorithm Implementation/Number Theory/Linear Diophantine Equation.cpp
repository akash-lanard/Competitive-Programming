bool linearDiophantine(LL A, LL B, LL C, LL *X, LL *Y) {
    LL g = gcd(A, B);
    if(C%g!=0) return false;     /// no solution

    LL a = A/g, b = B/g, c = C/g;
    ext_gcd(a, b, X, Y);        /// solve aX + bY = 1

    if(g<0) {                   /// make sure gcd(a, b) = 1
        a *= ((LL)(-1)); b *= ((LL)(-1)); c *= ((LL)(-1));
    }
    *X *= c; *Y *= c;           /// aX + bY = c
    return true;
}

int main () {
    LL x, y, A = 2, B = 3, C = 5;
    bool res = linearDiophantine ( A, B, C, &x, &y );

    if ( res == false ) printf ( "No Solution\n" );
    else {
        printf ( "One Possible Solution (%lld %lld)\n", x, y );

        LL g = gcd ( A, B );

        LL k = 1; //Use different value of k to get different solutions
        printf ( "Another Possible Solution (%lld %ld)\n", x + k * ( B / g ), y - k * ( A / g ) );
    }

    return 0;
}
