#include <stdio.h>
#include <stdlib.h>
int main() {
    int*n,*p;
    int i,n1,n2;
    printf("请输入所要创建的动态数组的长度：");
    scanf("%d",&n1);
    n=(int*)calloc(n1,sizeof(int));
    for(i=0; i<n1; i++) {
        n[i]=i+1;
        if(i%5==0)
            printf("\n");
        printf("%d\t",n[i]);
    }
    printf("\n请输入所要缩小的动态数组的长度：");
    scanf("%d",&n2);
    p=(int*)realloc(n,(n2)*sizeof(int));
    for(i=0; i<n2; i++) {
        if(i%5==0)
            printf("\n");
        printf("%d\t",p[i]);
    }
    printf("\n");
    free(p);
    return 0;
}
