#include<stdio.h>
//想法一
void printbin(int dec) {
	int bin=1;
	while (bin<=dec) {
		bin*=2;
	}
	//dec=9,bin=16
	//bin=8
	//9>=8 dec=9-8=1 print 1
	//bin=4,dec=1
	//1<4 print 0
	//bin=2,dec=1
	//1<2 print 0
	//bin=1,dec=1
	//1>=1 print 1
	//bin=0,dec=0

	//dec=10,bin=16
	//bin=8
	//10>=8 dec=10-8=2 print 1
	//bin=4,dec=2
	//2<4 print 0
	//bin=2,dec=2
	//2>=2 dec=2-2 print 1
	//bin=1,dec=0
	//0<1 print 0
	//bin=0,dec=0

	while (1) {
		//printf("%d-%d ",dec,bin);
		bin /= 2;
		if (dec==0 && bin==0) { break; }
		if (dec >= bin) { printf("1"); dec -= bin; }
		else { printf("0"); }
	}
	printf("\n");
}
int main() {
	int i;
	for(i=0;i<30;i++) {
		printf("%d: ",i);
		printbin(i);
	}
	return 0;
}
