#include<stdio.h>
#define MAX_N 10
void print(int *,int );
void permutation(int ,int );
int used[MAX_N];
int perm[MAX_N];
void permutation(int pos,int n) {
    if(pos==n) {
        print(perm,n);
        return ;
    }
    int i;
    for(i=0; i<n; i++) {
        if(!used[i]) {
            perm[pos]=i+1;
            used[i]=1;
            permutation(pos+1,n);
            used[i]=0;
        }
    }
    return ;
}
void print(int *a,int n) {
    int i;
    for(i=0; i<n; i++) {
        printf(" %d",a[i]);
    }
    printf("\n");
}
int main() {
    int n=3;
    permutation(0,n);
    return 0;
}
