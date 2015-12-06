
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int f_recursive(int n) {

    int u1, u2, f;
    if (n < 2)
        f = n + 1;
    else {
        u1 = f_recursive((int)(n/2));
        u2 = f_recursive((int)(n/4));
        f = u1 * u2;
    }
    return f;
}
int main() {
    int i;
    for(i=0; i<20; i++) {
        printf("f(%d)=%d\n",i,f_recursive(i));
    }
    return 0;
}
