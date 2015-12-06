
/*interface*/
/*interface implementation*/
Cyclic Shift :-
static long hashCode(String key, int D)
{
  int h=0;
  for (int i=0, i<key.length(); i++)
  {
        h = (h << 4) | ( h >> 27);
        h += (int) key.charAt(i);
  }
  return h%D;
}


/*client*/
#include<stdio.h>
int main() {
	return 0;
}
