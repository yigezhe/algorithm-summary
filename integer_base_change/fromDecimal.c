#include<stdio.h>
int fromDecimal(int n, int b) {
    int result=0;
    int multiplier=1;

    while(n>0) {
        result+=n%b*multiplier;
        multiplier*=10;
        n/=b;
    }

    return result;
}
void fromDecimal2(int n, int b, char* result,int* size) {
    char chars[]="0123456789ABCDEFGHIJ";

    while(n>0) {
    printf("size=%d\n",*size);
        //result=chars[n%b] + result;
        //先做一个后移
	int i;
        for(i=(*size); i>0; i--) {
            *(result+i)= *(result+i-1);
        }
        result[0]=chars[n%b];
        (*size)++;
        result[*size]='\0';
	printf("%s\n",result);
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
    int n=1087;
    int b=16;
    int size=0;
    result[size]='\0';
    printf("%d at %d = \n",n,b);
    fromDecimal2(n, b, result,&size);
    result[size]='\0';
    printf("%s\n",result);

    return 0;
}
