void number_char_array(int num,char *char_array) {
	int i=0;
	//int 2^32-1
	//可以由int是几位整数来决定temp是几位数组！ 
	char temp[20];
	int remainder=num;
	if (num==0) {
		char_array[0]='0';
		char_array[1]='\0';
		return;
	}
	while(num != 0) {
		remainder=num%10;
		temp[i]='0'+remainder;
		num/=10;
		i++;
	}
	if (i>=20) { printf("%d>=20 出界了！",i);exit(1);}
	temp[i]='\0';
	int j,k=0;
	for(j=i-1;j>=0;j--) {
		char_array[k]=temp[j];
		k++;
	}
	char_array[k]='\0';
}
