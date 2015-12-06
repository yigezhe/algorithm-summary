/*Lucas定理，设p是一个素数（题目中要求取模的数也是素数），将n,m均转化为p进制数，表示如下：

满足下式：


即C(n,m)模p等于p进制数上各位的C(ni,mi)模p的乘积。利用该定理，可以将计算较大的C(n,m)转化成计算各个较小的C(ni,mi)。
该方案能支持整型范围内所有数的组合数计算，甚至支持64位整数，注意中途溢出处理。该算法的时间复杂度跟n几乎不相关了，可以认为算法复杂度在常数和对数之间。
*/

#include <stdio.h>
//令M＝＝1相当于取消了取模！
#define M 10007
int ff[M+5];  //打表，记录n!，避免重复计算

//求最大公因数
int gcd(int a,int b) {
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

//解线性同余方程，扩展欧几里德定理
int x,y;
void Extended_gcd(int a,int b) {
    if(b==0) {
        x=1;
        y=0;
    } else {
        Extended_gcd(b,a%b);
        long t=x;
        x=y;
        y=t-(a/b)*y;
    }
}

//计算不大的C(n,m)
int C(int a,int b) {
    if(b>a)
        return 0;
    b=(ff[a-b]*ff[b])%M;
    a=ff[a];
    int c=gcd(a,b);
    a/=c;
    b/=c;
    Extended_gcd(b,M);
    x=(x+M)%M;
    x=(x*a)%M;
    return x;
}

//Lucas定理
int Combination(int n, int m) {
    int ans=1;
    int a,b;
    while(m||n) {
        a=n%M;
        b=m%M;
        n/=M;
        m/=M;
        ans=(ans*C(a,b))%M;
    }
    return ans;
}

int main(void) {
    int i,m,n;
    ff[0]=1;
    for(i=1; i<=M; i++) //预计算n!
        ff[i]=(ff[i-1]*i)%M;

    //令M＝1是不行的！
    scanf("%d%d",&n, &m);
    printf("%d\n",Combination(n,m));

    return 0;
}

