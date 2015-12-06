//http://blog.sina.com.cn/s/blog_4298002e0100eko0.html
/*interface*/
/*interface implementation*/
double lnchoose(int n, int m) {
    if (m > n) {
        return 0;
    }
    if (m < n/2.0) {
        m = n-m;
    }
    double s1 = 0;
    for (int i=m+1; i<=n; i++) {
        s1 += log((double)i);
    }
    double s2 = 0;
    int ub = n-m;
    for (int i=2; i<=ub; i++) {
        s2 += log((double)i);
    }
    return s1-s2;
}
double choose(int n, int m) {
    if (m > n) {
        return 0;
    }
    return exp(lnchoose(n, m));
}
/*client*/
#include<stdio.h>
int main() {
    return 0;
}
