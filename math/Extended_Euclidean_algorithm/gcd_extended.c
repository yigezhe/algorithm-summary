//来自http://zh.wikipedia.org/wiki/扩展欧几里得算法
int gcdEx(int a, int b, int *x, int *y) {
	if(b==0) {
		*x = 1,*y = 0;
		return a;
	} else {
		int r = gcdEx(b, a%b, x, y);
		int t = *x;
		*x = *y;
		*y = t - a/b * *y;
		return r;
	}
}
//还可以把x，y作为一个共同体来处理！
