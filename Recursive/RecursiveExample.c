#include<stdio.h>
int calculate(int m)  
{  
	int count = 0;  
	if(m <0)  
		return -1;  

	for(int index = 0; index <= m; index++)  
		count += index;  

	return count;  
}  
int calculateRecursive(int m)  
{  
	if(m == 0)  
		return 0;  
	else  
		return calculateRecursive(m -1) + m;  
}  
int main() {
	printf("%d\n",calculate(10));
	printf("%d\n",calculateRecursive(10));
	return 0;
}
