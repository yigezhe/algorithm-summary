#include<stdio.h>
void fromDecimal2(int n, int b, char* result,int* size) {
    char chars[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if(n==0){
        result[0]=chars[n%b];
        (*size)++;
	return ;
    }

    while(n>0) {
        //printf("size=%d\n",*size);
        //result=chars[n%b] + result;
        //先做一个后移
        int i;
        for(i=(*size); i>0; i--) {
            *(result+i)= *(result+i-1);
        }
        result[0]=chars[n%b];
        (*size)++;
        result[*size]='\0';
        //printf("%s\n",result);
        n/=b;
    }

}
int main() {
    /*
    int n=8;
    int b=2;
    printf("%d at %d = %d\n",n,b,fromDecimal(n,b));
    */
    char result[100];
    int b=26;
    int n;
    for(n=0; n<=100; n++) {
        int size=0;
        result[size]='\0';
        printf("%d at %d = ",n,b);
        fromDecimal2(n, b, result,&size);
        result[size]='\0';
        printf("%s\n",result);
    }

    return 0;
}
