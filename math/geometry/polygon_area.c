//交叉积，顺时针为负数，逆时针为正数！
#include<stdio.h>
#include<math.h>
double polygon_area(int p[][2],int n) {
    int area = 0;
//We will triangulate the polygon
//into triangles with points p[0],p[i],p[i+1]

    int i;
    for(i = 1; i+1<n; i++) {
        int x1 = p[i][0] - p[0][0];
        int y1 = p[i][1] - p[0][1];
        int x2 = p[i+1][0] - p[0][0];
        int y2 = p[i+1][1] - p[0][1];
        int cross = x1*y2 - x2*y1;
        area += cross;
    }
    return area/2.0;
}
int main() {
	//ABCDE
	//(-5,1)
	//(-1,5)
	//(1,1)
	//(-2,-3)
	//(-1,1)
	int a[5][2]={{-5,1},{-1,5},{1,1},{-2,-3},{-1,1}};
	printf("polygon area a is %f\n",polygon_area(a,5));
    return 0;
}
