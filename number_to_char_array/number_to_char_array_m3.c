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

	//直接颠倒顺序就可以！
        int k;
        char mid_char_reverse[10];
        for(k=j-1; k>=0; k--) {
            mid_char_reverse[j-1-k]=mid_char[k];
        }
        printf("%s\n",mid_char_reverse);
    }
    return 0;
}
