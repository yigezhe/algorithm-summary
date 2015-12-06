
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
	return 0;
}
// warning: untested code.
size_t hash(char const *input) { 

    const int ret_size = 32;
    size_t ret = 0x555555;
    const int per_char = 7;

    while (*input) { 
        ret ^= *input++;
        ret = ((ret << per_char) | (ret >> (ret_size - per_char));
   }
   return ret;
}
