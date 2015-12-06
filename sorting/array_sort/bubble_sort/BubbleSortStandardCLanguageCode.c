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
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			//把大的往后面换！
			if (array[j] > array[j + 1]) {
				int arrayjOrigin = array[j];
				array[j] = array[j + 1];
				array[j + 1] = arrayjOrigin;
			}
		}
printArray (array,size) ;
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

