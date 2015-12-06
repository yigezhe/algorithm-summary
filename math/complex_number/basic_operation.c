#include <complex.h>
#include <stdio.h>

int main(void) {
	//表示复数！
    double complex cx = 1.0 + 3.0*I;
    double complex  cy = 1.0 - 4.0*I;
    printf("Working with complex numbers:");
    //这是打印复数的一种方式！
    printf("\nStarting values: cx = %.2f%+.2fi  cy = %.2f%+.2fi", creal(cx), cimag(cx), creal(cy), cimag(cy));

    double complex  sum = cx+cy;
    printf("\n\nThe sum cx + cy = %.2f%+.2fi", creal(sum),cimag(sum));

    double complex  difference = cx-cy;
    printf("\n\nThe difference cx - cy = %.2f%+.2fi", creal(difference),cimag(difference));

    double complex product = cx*cy;
    printf("\n\nThe product cx * cy = %.2f%+.2fi",creal(product),cimag(product));

    double complex quotient = cx/cy;
    printf("\n\nThe quotient cx / cy = %.2f%+.2fi", creal(quotient),cimag(quotient));

    //这是求对称复数！
    double complex conjugate = conj(cx);
    printf("\n\nThe conjugate of cx =  %.2f%+.2fi", creal(conjugate) ,cimag(conjugate));
    //这时求角度
    double complex argument = carg(cx);
    printf("\n\nThe argument of cx =  %.2f%+.2fi", creal(argument) ,cimag(argument));

    //复数在黎曼曲面上的对应点！
    double complex projection = cproj(cx);
    printf("\n\nThe projection of cx =  %.2f%+.2fi", creal(projection) ,cimag(projection));

    return 0;
}
