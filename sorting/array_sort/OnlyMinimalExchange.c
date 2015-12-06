#include<stdio.h>
#define MAXSIZE 50

void printArray (int array[],int size) {
	int i;
	printf ("{%d", array[0]);
	for (i = 1; i < size; i++)
		printf (", %d", array[i]);
	printf ("}\n");

}
//这个代码还可以改进，暂时先用着！
void sort(int array[],int size) {
	int i, j;

	for (i = 0; i < size-1; i++) {// 因为i＝size－1时，后面的不用比较了！
		int smallest_i = i;
		int smallest = array[i];
		//通过比较找到最小的那个值的位置
		for (j = i + 1; j < size; j++) {
			if (array[j] < smallest) {
				smallest = array[j];
				smallest_i = j;
			}
		}
		//把最小的与当前值交换！
		//交换i与smallest_i的位置，这里有可能i与smallest_i是相同的我们还进行了交换！
//但是这个多余的工作对于高速运行的cpu来说，不进行优化也是可以的！
		int arrayi_origin = array[i];
		array[i] = array[smallest_i];
		array[smallest_i] = arrayi_origin;

		printArray (array,size);
	}
}

int main () {
	int array[MAXSIZE];
	int size = 5;
	array[0] = 5;
	array[1] = 4;
	array[2] = 3;
	array[3] = 2;
	array[4] = 1;
	sort(array,size);
	return 0;
}
