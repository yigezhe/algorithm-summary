#include<stdio.h>
#define MAX 10
int main() {
    int a[MAX];
    a[0]=1;
    a[1]=2;
    a[2]=4;
    a[3]=5;
    a[4]=6;
    int n=5;
    int value=3;
    int low=0;
    int high=n-1;
    while(low<=high) {
        int mid=(low+high)/2;
        //low mid value high
        //low value mid high
        if(a[mid]<value)
            low=mid+1;
        else
            high=mid-1;
    }
    int k;
    int i;
    for(i=0; i<n; i++) {
        printf(" %d",a[i]);
    }
    printf("\n");
    printf("low is %d\n",low);
    printf("high is %d\n",high);

    /*
       使用low
    for(k=n;k>=low;k--){
    	a[k]=a[k-1];
    }
    */
    //使用high
    for(k=n; k>high; k--) {
        a[k]=a[k-1];
    }

    a[high+1]=value;
    n++;
    for(i=0; i<n; i++) {
        printf(" %d",a[i]);
    }
    printf("\n");
    return 0;
}
