#include<stdio.h>
#define MAXN 50
int array[MAXN];

void printArray (int array[],int size) {
	int i;
	printf ("{%d", array[0]);
	for (i = 1; i < size; i++)
		printf (", %d", array[i]);
	printf ("}\n");

}

void sort(int array[],int size) {
	int i, j;
	for (i = 0; i < size-1; i++) {
		for (j = i + 1; j < size; j++) {
			if (array[j] < array[i])
			{
				int arrayi_origin = array[i];
				array[i] = array[j];
				array[j] = arrayi_origin;
			}
		}
		printArray (array,size);
	}
}

int main () {
	int size = 5;
	array[0] = 5;
	array[1] = 4;
	array[2] = 3;
	array[3] = 2;
	array[4] = 1;
	sort(array,size);
	return 0;
}

