long long power(long long a, long long b, long long Mod){
    if(b == 0)
        return 1;
    long long val = power(a,b/2,Mod);
    val = ((val+Mod)*(val+Mod))%Mod;
    if(b%2 != 0)
        val = ((val*a) +(val*Mod))%Mod;
    return val;
}
 
int Solution::pow(int x, int n, int d) {
    if(x != 0)
    return (int)power(x,n,d);
    return 0;
}