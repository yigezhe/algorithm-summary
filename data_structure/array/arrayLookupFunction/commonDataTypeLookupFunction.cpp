/*这里我跟着作者的思路来工作！*/
#include<cstdio>
template<typename type>
/*
type array[]测试了一下不能用！
int find(type array[], int length, int value)
{
	// 判断参数的合法性
	if(NULL == array || 0 == length)
		return -2;
	int index = 0;
	//这里算是作者偷了一个懒！本来要写for（index＝0；index《。。。
	for(; index < length; index++){
		if(value == array[index])
			return index;
	}

	return -1;
}
*/
int findPointerVersion(type array[], int length, int value) {
    if(NULL == array || 0 == length)
        return -2;

    type* start = array;
    type* end = array + length;
    while(start < end) {
        if(value == *start)
            //直接计算两个地址之间的距离，除以一个数据占用几个数据！
            return ((long)start - (long)array)/(sizeof(type));
        start ++;
    }

    return -1;
}
void test_find() {
    int array[10]= {0};
    printf("%d\n",find<int>(NULL,10,10));
    printf("%d\n",find<int>(array,0,10));
    int array2[10]= {1,2};
    printf("%d\n",find<int>(array2,10,1));
    printf("%d\n",find<int>(array2,10,10));
}
void test_findPointerVersion() {
    int array[10]= {0};
    printf("%d\n",findPointerVersion<int>(NULL,10,10));
    printf("%d\n",findPointerVersion<int>(array,0,10));
    int array2[10]= {1,2};
    printf("%d\n",findPointerVersion<int>(array2,10,1));
    printf("%d\n",findPointerVersion<int>(array2,10,10));
}
/*
   我不接受作者的这个测试函数！
   static void test1()
   {
   type array[10] = {0};
   assert(FALSE == find(NULL, 10, 10));
   assert(FALSE == find(array, 0, 10));
   }
 */
int main() {
    test_find();
    printf("---两者应该相同！-----\n");
    test_findPointerVersion();
    return 0;
}
