#include<stdio.h>
int main() {
    //int mid=size-2;

    int mid;
    for(mid=0; mid<50; mid++) {
        int mid_tmp=mid;
        char mid_char[10];
        int j=0;
        while(1) {
            mid_char[j]='0'+mid_tmp%10;
            j++;
            mid_tmp = mid_tmp / 10;
            if (mid_tmp==0) break;
        }
        mid_char[j]='\0';
        //printf("mid char = %s -- ",mid_char);

        int k;
        for(k=j-1; k<=j/2; k++) {
            char tmp=mid_char[k];
            mid_char[k]=mid_char[j-1-k];
            mid_char[j-1-k]=tmp;
        }
        printf("%s\n",mid_char);
    }
    return 0;
}
