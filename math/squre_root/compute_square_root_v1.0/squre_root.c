#include<stdio.h>
short isqrt ( short num ) {
    short res = 0;
    short bit = 1 << 14; // The second-to-top bit is set: 1 << 30 for 32 bits

    // "bit" starts at the highest power of four <= the argument.
    while ( bit > num )
        bit >>= 2;

    while ( bit != 0 ) {
        if ( num >= res + bit ) {
            num -= res + bit;
            res = ( res >> 1 ) + bit;
        } else
            res >>= 1;
        bit >>= 2;
    }
    return res;
}
int isqrti ( int num ) {
    int res = 0;
    int bit = 1 << 30; // The second-to-top bit is set: 1 << 30 for 32 bits

    // "bit" starts at the highest power of four <= the argument.
    while ( bit > num )
        bit >>= 2;

    while ( bit != 0 ) {
        if ( num >= res + bit ) {
            num -= res + bit;
            res = ( res >> 1 ) + bit;
        } else
            res >>= 1;
        bit >>= 2;
    }
    return res;
}

int main() {
	printf("sqrt(%d)=%d\n",2,isqrt(2));
	printf("sqrt(%d)=%d\n",8,isqrt(8));
	printf("sqrt(%d)=%d\n",2,isqrti(2));
	printf("sqrt(%d)=%d\n",8,isqrti(8));

	return 0;
}
