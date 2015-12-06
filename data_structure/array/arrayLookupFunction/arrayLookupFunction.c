/*这里我跟着作者的思路来工作！*/
#include<stdio.h>
int find(int array[], int length, int value) {
    // 判断参数的合法性
    if(NULL == array || 0 == length)
        return -2;
    int index = 0;
    //这里算是作者偷了一个懒！本来要写for（index＝0；index《。。。
    for(; index < length; index++) {
        if(value == array[index])
            return index;
    }

    return -1;
}
int findPointerVersion(int array[], int length, int value) {
    if(NULL == array || 0 == length)
        return -2;

    int* start = array;
    int* end = array + length;
    while(start < end) {
        if(value == *start)  {
            //直接计算两个地址之间的距离，除以一个数据占用几个数据！
            printf("(int)start=%d\n(int)array=%d)\nsizeof(int)=%lu\nsizeof(long)=%lu\n",(int)start,(int)array,sizeof(int),sizeof(long));
            return ((int)start - (int)array)/(sizeof(int));
        }
        start ++;
    }

    return -1;
}
int _findRecursiveVersion(int index, int array[], int length, int value) {
    if(index == length)
        return -1;

    if(value == array[index])
        return index;

    return _findRecursiveVersion(index + 1,  array, length, value);
}

int findRecursiveVersion(int array[], int length, int value) {
    if(NULL == array || length == 0)
        return -2;

    //这个方式可以减少一些参数！就是在母函数里不多检查参数，在子函数里添加更多的参数来做检查！ _findRecursiveVersion(0, array, length, value);
    return _findRecursiveVersion(0, array, length, value);
}
void test_find() {
    int array[10]= {0};
    printf("%d\n",find(NULL,10,10));
    printf("%d\n",find(array,0,10));
    int array2[10]= {1,2};
    printf("%d\n",find(array2,10,1));
    printf("%d\n",find(array2,10,10));
}
void test_findPointerVersion() {
    int array[10]= {0};
    printf("%d\n",findPointerVersion(NULL,10,10));
    printf("%d\n",findPointerVersion(array,0,10));
    int array2[10]= {1,2};
    printf("%d\n",findPointerVersion(array2,10,1));
    printf("%d\n",findPointerVersion(array2,10,10));
}
void test_findRecursiveVersion() {
    int array[10]= {0};
    printf("%d\n",findRecursiveVersion(NULL,10,10));
    printf("%d\n",findRecursiveVersion(array,0,10));
    int array2[10]= {1,2};
    printf("%d\n",findRecursiveVersion(array2,10,1));
    printf("%d\n",findRecursiveVersion(array2,10,10));
}

/*
   我不接受作者的这个测试函数！
   static void test1()
   {
   int array[10] = {0};
   assert(FALSE == find(NULL, 10, 10));
   assert(FALSE == find(array, 0, 10));
   }
 */
int main() {
    printf("---array版本！-----\n");
    test_find();
    printf("---Pointer版本！-----\n");
    test_findPointerVersion();
    printf("---Recursive版本！-----\n");
    test_findRecursiveVersion();
    return 0;
}
