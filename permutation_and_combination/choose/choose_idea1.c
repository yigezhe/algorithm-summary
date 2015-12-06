long long choose(long long n,long long k) {
    if(n==k) {
        return 1;
    } else if(n<k) {
        return 0;
    } else {
        long long res=1;
        long long i;
        for(i=0; i<k; i++) {
            res*=(n-i);
        }
        for(i=1; i<=k; i++) {
            res/=i;
        }
        return res;
    }
}
int main() {
	
}
