bool isPrime(int n) {
    if(n==1) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    if(n==3 || n==5) return true;

    int lim = sqrt(n);
    for(int i=3; i<=lim; i+=2) {
        if(n%i==0) return false;
    }
    return true;
}
