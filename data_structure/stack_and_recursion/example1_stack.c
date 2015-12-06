#include<stdio.h>
int f_nonrecursive(int n) {

    int stack[20], flag[20], cp;
    /* 初始化栈和栈顶指针 */
    cp = 0;
    stack[0] = n;
    flag[0] = 0;
    while (cp >= 0) {
        switch(flag[cp]) {
        case 0: 			/* 访问的是根结点 */
            if (stack[cp] >= 2) {	/* 左子树入栈 */
                flag[cp] = 1; 	/* 修改标志域 */
                cp++;
                stack[cp] = (int)(stack[cp - 1] / 2);
                flag[cp] = 0;
            } else { 		/* 否则为叶子结点 */
                stack[cp] += 1;
                flag[cp] = 2;
            }
            break;
        case 1: 			/* 访问的是左子树 */
            if (stack[cp] >= 2) {	/* 右子树入栈 */
                flag[cp] = 2; 	/* 修改标志域 */
                cp += 2;
                stack[cp] = (int)(stack[cp - 2] / 4);
                flag[cp] = 1;
            } else { 		/* 否则为叶子结点 */
                stack[cp] += 1;
                flag[cp] = 2;
            }
            break;
        case 2:				 /* */
            if (flag[cp - 1] == 2) { /* 当前是右子树吗? */
                /*
                 * 如果是右子树, 那么对某一棵子树的后序遍历已经
                 * 结束,接下来就是对这棵子树的根结点的访问
                 */
                stack[cp - 2] = stack[cp] * stack[cp - 1];
                flag[cp - 2] = 2;
                cp = cp - 2;
            } else
                /* 否则退回到后序遍历的上一个结点 */
                cp--;
            break;
        }
    }
    return stack[0];
}
int main() {
    int i;
    for(i=0; i<20; i++) {
        printf("f(%d)=%d\n",i,f_nonrecursive(i));
    }
    return 0;
}
