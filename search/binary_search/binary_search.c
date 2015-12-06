#include<stdio.h>
int search(int *a,int key,int low,int high) {
	int mid;
	if(low > high)
		return -1;
	mid = (low + high)/2;
	if(a[mid] == key) return mid;
	else if(a[mid] > key)return search(a,key,low,mid -1);
	else return search(a,key,mid + 1,high);
}
int main() {
	int a[] = {1,2,3,4,5,6,7,8,9,12,13,45,67,89,99,101,111,123,134,565,677};
	int i = search(a,99,0,sizeof(a)/sizeof(a[0])-1);
	printf("find 99 at %d\n",i);
	return 0;
}
