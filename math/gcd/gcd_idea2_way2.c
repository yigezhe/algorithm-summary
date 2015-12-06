#include<stdio.h>

int gcd(int a,int b) {
    int r;
//保证在处理正整数！
    if(a<0) {
        a=-a;
    }
    if(b<0) {
        b=-b;
    }
//这里保证a大于b
    if(b>a) {
        int tmp=a;
        a=b;
        b=tmp;
    }

//我喜欢符合数学的符号使用！
    //这里使用的是辗转相除
    //a=b*q1+r1;
    //0<=r1<b,a>b
    //当r1=0，a=bq1,a和b的最大公约数是b,约数不可能比b大！
    //当r1!=0,0<r1<b
    //b=r1*q2+r2
    //a=(r1*q2+r2)*q1+r1;
    //a=r1*q1*q2+r2*q1+r1;
    //当r2=0，b=r1*q2,b和r1的最大公约数是r1,约数不可能比b大！
    //b=r1*q2
    //a=r1*q1*q2+r1=r1*(q1*q2+1)
    //从素数理论指导，p1p2...pn+1不能被pi整除
    //有q2无法整除q1*q2+1
    //所以a和b的最大公约数是r1
    //其实说来基本技术是gcd(a,b)=gcd(b,r),a=b*q+r,0<r<b
    //把这个替换坚持到r＝0，则b就是我们想要的答案！
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    //gcd(4,6);
    int i,j;
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            printf("%2d",gcd(i,j));
        }
        printf("\n");
    }
    return 0;
}
