#include <stdio.h>
#include <stdlib.h>
void *MemAlloc(unsigned int ulMemSize) {
    return malloc(ulMemSize);
}
void MemFree(void **ppvFree) {
    free(*ppvFree);
    *ppvFree = 0;
}
/* 裴波那契数列非递归实现 */
/* 栈元素内存可以优化，在此不做优化， 仅仅供学习参考 */
unsigned int FibnoFunction(unsigned int ulNum) {
    unsigned int *pulStackBt;
    unsigned int *pulStackTop;
    unsigned int ulSumRet;
    pulStackBt = MemAlloc(sizeof(unsigned int)*(ulNum+ 1));
    if (pulStackBt == 0) {
        return -1;
    }
    /* 初始化栈 */
    pulStackTop = pulStackBt + ulNum;
    pulStackTop[0] = 0;
    if (ulNum > 0) {
        pulStackTop[-1] = 1;
    }
    /* 依次出栈 */
    //没有真正运用栈!
    //我可以直接用数组实现，而取消作者伪装的栈外表！
    while (pulStackTop > pulStackBt + 1) {
        pulStackTop[-2] = pulStackTop[-1] + pulStackTop[0];
        pulStackTop--;
    }
    ulSumRet = *pulStackBt;
    MemFree(&pulStackBt);
    return ulSumRet;
}
//int main(int args, unsigned char **ppargs) {
int main() {
    unsigned int ulFebSum = 0;
    for (ulFebSum = 0; ulFebSum < 15; ulFebSum++) {
        printf("FibnoFunction(%u) = %u\r\n", ulFebSum, FibnoFunction(ulFebSum));
    }
    return 0;
}
