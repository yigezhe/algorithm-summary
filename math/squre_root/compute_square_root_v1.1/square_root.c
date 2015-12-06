//http://www.codeproject.com/Articles/570700/SquareplusRootplusalgorithmplusforplusC
//我有时间再仔细研究这个代码！
#include<stdio.h>
double powerOfTen(int num) {
    double rst = 1.0;
    int i;
    if(num >= 0) {
        for(i = 0; i < num ; i++) {
            rst *= 10.0;
        }
    } else {
        for(i = 0; i < (0 - num ); i++) {
            rst *= 0.1;
        }
    }
    return rst;
}
double
squareRoot ( double a ) {
    /*
     * find more detail of this method on wiki
     * methods_of_computing_square_roots
     *
     * Babylonian method cannot get exact zero but approximately value of
     * the square_root
     */
    double z = a;
    double rst = 0.0;
    int	max = 8;
    //to define maximum digit
    int	i;
    double j = 1.0;
    for ( i = max; i > 0; i-- ) {
        //value must be bigger then 0
        if ( z - ( ( 2 * rst ) + ( j * powerOfTen ( i ) ) ) * ( j * powerOfTen ( i ) ) >= 0 ) {
            while ( z - ( ( 2 * rst ) + ( j * powerOfTen ( i ) ) ) * ( j * powerOfTen ( i ) ) >= 0 ) {
                j++;
                if ( j >= 10 )
                    break;

            }
            j--;
            //correct the extra value by minus one to j
            z -= ( ( 2 * rst ) + ( j * powerOfTen ( i ) ) ) * ( j * powerOfTen ( i ) );
            //find value of z

            rst += j * powerOfTen ( i );
            //find sum of a

            j = 1.0;


        }
    }

    for ( i = 0; i >= 0 - max; i-- ) {
        if ( z - ( ( 2 * rst ) + ( j * powerOfTen ( i ) ) ) * ( j * powerOfTen ( i ) ) >= 0 ) {
            while ( z - ( ( 2 * rst ) + ( j * powerOfTen ( i ) ) ) * ( j * powerOfTen ( i ) ) >= 0 ) {
                j++;

            }
            j--;
            z -= ( ( 2 * rst ) + ( j * powerOfTen ( i ) ) ) * ( j * powerOfTen ( i ) );
            //find value of z

            rst += j * powerOfTen ( i );
            //find sum of a
            j = 1.0;
        }
    }
    //find the number on each digit
    return rst;
}
int main() {
	int num=2;
	printf("sqrt(%d)=%f\n",num,squareRoot(num));
	return 0;
}
