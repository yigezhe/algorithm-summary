#include <stdio.h>
#include <stdlib.h>
int main() {
    int*n,*p;
    int i,n1,n2;
    printf("请输入所要创建的动态数组的长度：");
    scanf("%d",&n1);
    n=(int*)calloc(n1,sizeof(int));
    printf("请输入所要扩展的动态数组的长度：");
    scanf("%d",&n2);
    p=(int*)realloc(n,(n2)*sizeof(int));//动态扩充数组
    for(i=0; i<n2; i++) {
        p[i]=i+1;
        if(i%5==0)
            printf("\n");
        printf("%d\t",p[i]);
    }
    free(p);
    return 0;
}
