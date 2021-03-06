#include<stdio.h>
#include<math.h>
//Compute the dot product AB ⋅ BC
double dabs(double a) {
	if(a<0) return -a;
	else return a;
}
int dot(int A[2], int B[2], int C[2]) {
    int AB[2];
    int BC[2];
    AB[0] = B[0]-A[0];
    AB[1] = B[1]-A[1];
    BC[0] = C[0]-B[0];
    BC[1] = C[1]-B[1];
    int dot = AB[0] * BC[0] + AB[1] * BC[1];
    return dot;
}
//Compute the cross product AB x AC
int cross(int A[2], int B[2], int C[2]) {
    int AB[2];
    int AC[2];
    AB[0] = B[0]-A[0];
    AB[1] = B[1]-A[1];
    AC[0] = C[0]-A[0];
    AC[1] = C[1]-A[1];
    int cross = AB[0] * AC[1] - AB[1] * AC[0];
    return cross;
}
//Compute the distance from A to B
double distance(int A[2], int B[2]) {
    int d1 = A[0] - B[0];
    int d2 = A[1] - B[1];
    return sqrt(d1*d1+d2*d2);
}
//Compute the distance from AB to C
//if isSegment is true, AB is a segment, not a line.
double linePointDist(int A[2], int B[2], int C[2], int isSegment) {
    double dist = cross(A,B,C) / distance(A,B);
    if(isSegment) {
        int dot1 = dot(A,B,C);
        if(dot1 > 0)return distance(B,C);
        int dot2 = dot(B,A,C);
        if(dot2 > 0)return distance(A,C);
    }
    return dabs(dist);
}
int main() {
    int a[2]= {1,2};
    int b[2]= {2,1};
    int c[2]= {0,0};
printf("c to AB segment distance is %f\n",linePointDist(a,b,c,1));
    return 0;
}
