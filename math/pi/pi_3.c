
//Here we try out a small program that computes the value of Pi using the following formula:
//Pi = 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - ... )
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    double t, k = 3.0, l = -1.0;
    int i, s;

    if(argc < 2) {
        fprintf(stderr, "%s <number of iterations>\n", argv[0]);
        exit(1);

    }

    t = 1.0;
    for(i = 0, s = atoi(argv[1]); i < s; i++) {
        t += l/k;
        k += 2.0;
        l *= -1.0;

    }
    t *= 4;
    printf("My value of Pi: %.16f, math.h's value of Pi: %.16f\n", t, M_PI);
    //printf("My value of Pi: %1.6f, math.h's value of Pi: %.16f\n", t, M_PI);
    printf("Absolute difference: %.16f\n", fabs(M_PI - t));

    return 0;
}
