#include<vector>
using namespace std;
//http://my.oschina.net/baoer1024/blog/62826
/*interface*/
/*interface implementation*/
/*质因数分解，C(n,m)=n!/(m!*(n-m)!)，设n!分解因式后，质因数p的次数为a；对应地m!分解后p的次数为b；(n-m)!分解后p的次数为c；则C(n,m)分解后，p的次数为a-b-c。计算出所有质因子的次数，它们的积即为答案，即C(n,m)=p1 a1-b1-c1p2 a2-b2-c2…pk ak-bk-ck。n!分解后p的次数为：n/p+n/p 2+…+n/p k。
算法的时间复杂度比前两种方案都低，基本上跟n以内的素数个数呈线性关系，而素数个数通常比n都小几个数量级，例如100万以内的素数不到8万个。用筛法生成素数的时间接近线性。该方案1秒钟能计算 1kw数量级的组合数。如果要计算更大，内存和时间消耗都比较大。
*/

//用筛法生成素数
const int MAXN = 1000000;
bool arr[MAXN+1] = {false};
vector<int> produce_prim_number() {
    vector<int> prim;
    prim.push_back(2);
    int i,j;
    for(i=3; i*i<=MAXN; i+=2) {
        if(!arr[i]) {
            prim.push_back(i);
            for(j=i*i; j<=MAXN; j+=i)
                arr[j] = true;
        }
    }
    while(i<=MAXN) {
        if(!arr[i])
            prim.push_back(i);
        i+=2;//只在奇数位上找素数！
    }
    return prim;
}

//计算n!中素因子p的指数
int Cal(int x, int p) {
    int ans = 0;
    long long rec = p;
    while(x>=rec) {
        ans += x/rec;
        rec *= p;
    }
    return ans;
}

//计算n的k次方对M取模，二分法
int Pow(long long n, int k) {
    long long ans = 1;
    while(k) {
        if(k&1) {
            ans = (ans * n);
        }
        n = (n * n);
        k >>= 1;
    }
    return ans;
}

//计算C(n,m)
int choose(int n, int k) {
//int Combination(int n, int m) {
    vector<int> prim = produce_prim_number();
    long long ans = 1;
    int num;
    for(int i=0; i<(int)prim.size() && prim[i]<=n; ++i) {
        num = Cal(n, prim[i]) - Cal(k, prim[i]) - Cal(n-k, prim[i]);
        ans = (ans * Pow(prim[i], num));
    }
    return ans;
}
/*client*/
#include<stdio.h>
int main() {
    int n,k;
    for(n=0; n<10; n++) {
        for(k=0; k<=n; k++) {
            printf(" %d",choose(n,k));
        }
        printf("\n");
    }
    return 0;
}
