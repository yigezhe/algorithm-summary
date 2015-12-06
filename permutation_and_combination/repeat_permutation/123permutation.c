#include<stdio.h>
#define N 1000000+1
int position[N];
void all_possibble(int pos,int n) {
    if(pos==n)  {
        int i;
        for(i=0; i<n; i++) {
            printf(" %3d",position[i]);
        }
        printf("\n");
        return;
    }
    position[pos]=1;
    all_possibble(pos+1,n);
    position[pos]=0;

    position[pos]=2;
    all_possibble(pos+1,n);
    position[pos]=0;

    position[pos]=3;
    all_possibble(pos+1,n);
    position[pos]=0;

    return;
}
int main() {
    all_possibble(0,1);
    printf("------------\n");
    all_possibble(0,2);
    printf("------------\n");
    all_possibble(0,3);
    printf("------------\n");
    all_possibble(0,4);
    return 0;
}
