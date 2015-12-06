#include<stdio.h>
#define N 100
#define INF 1000000000
//在这里记录路径更好！
int v[N];
int vn;
int recursive(int n) {
    printf("recursive(%d)\n",n);
    int result;
    if(n==0) {
        result=0;
    } else {
        int j;
        //这里选择最大值最好！
        int max_vj=0;
        for(j=0; j<vn; j++) {
            if(v[j]<=n && max_vj<v[j]) {
                max_vj=v[j];
            }
        }
        result=recursive(n-max_vj)+1;
    }
    return result;
}
int main() {
    v[0]=1,v[1]=3,v[2]=5;
    vn=3;
    int s=11;
    printf("%d\n",recursive(s));
    return 0;
}
