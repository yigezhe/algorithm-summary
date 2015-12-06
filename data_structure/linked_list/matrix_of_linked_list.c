
typedef struct node { int row, column,
	double value;
	struct node* rowPtr; struct node* colPtr;
} node;
typedef struct matrix {
	node** rowList; // rowList is a pointer to the array of rows
	node** columnList; // column list is a pointer to the array of columns.
	int rows, columns; // store the number of rows and columns of the matrix
} matrix;
/*interface*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*interface implementation*/
/*client*/
int main() {
	int *n=malloc(n*sizeof(int));
	if(n==NULL) {
		printf("n 没有分配到内存\n");
	}

	free(n);
	return 0;
}
