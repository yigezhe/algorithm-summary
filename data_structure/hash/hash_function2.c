
/*interface*/
/*interface implementation*/
/*client*/
int h(String x, int M) {
    char ch[];
    ch = x.toCharArray();
    int xlength = x.length();

    int i, sum;
    for (sum=0, i=0; i < x.length(); i++)
        sum += ch[i];
    return sum % M;
}
Folding Method:
-
int h(String x, int D) {
    int i, sum;
    for (sum=0, i=0; i<x.length(); i++)
        sum+= (int)x.charAt(i);
    return (sum%D);
}



#include<stdio.h>
int main() {
    return 0;
}
