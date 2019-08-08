#define SIZE 1000005
int phi[SIZE];

void euler_phi(int n){
    phi[1] = 1;
    for(int i = 2;i<=n;i++){
        if(!phi[i]){
            phi[i] = i-1;
            for(int j = (i<<1);j<=n;j+=i){
                if(!phi[j]){
                    phi[j] = j;
                }
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}
