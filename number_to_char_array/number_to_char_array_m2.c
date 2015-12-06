//我利用一下对数！
#include<stdio.h>
#include<math.h>
int main() {
    //int mid=size-2;
	//测试log10的效果！
	/*
	int i;
        for(i=1;i<20;i++) {
	       printf("%d %d\n",i,(int)log10(i));
	}
	*/

    int mid;
    for(mid=1; mid<20; mid++) {
	    //printf("mid = %d\n",mid);
        int mid_tmp=mid;
        char mid_char[10];
        int mid_size=1+(int)log10(mid);
	    //printf("mid size = %d\n",mid_size);
        int i;
        for (i=0; i<mid_size; i++) {
            mid_char[mid_size-1-i]='0'+mid_tmp%10;
            mid_tmp = mid_tmp / 10;
        }
        mid_char[mid_size]='\0';
        printf("number char array = %s\n",mid_char);
    }
    return 0;
}
