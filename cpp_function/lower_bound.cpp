#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
int main() {
    const int VECTOR_SIZE = 8 ;

    // Define a template class vector of int
    typedef vector<int > IntVector ;

    //Define an iterator for template class vector of strings
    typedef IntVector::iterator IntVectorIt ;

    IntVector Numbers(VECTOR_SIZE) ;

    IntVectorIt start, end, it, location ;

    // Initialize vector Numbers
    Numbers[0] = 4 ;
    Numbers[1] = 10;
    Numbers[2] = 11 ;
    Numbers[3] = 30 ;
    Numbers[4] = 69 ;
    Numbers[5] = 70 ;
    Numbers[6] = 96 ;
    Numbers[7] = 100;

    start = Numbers.begin() ;   // location of first
    // element of Numbers

    end = Numbers.end() ;       // one past the location
    // last element of Numbers

    // print content of Numbers
    cout << "Numbers { " ;
    for(it = start; it != end; it++)
        cout << *it << " " ;
    cout << " }\n" << endl ;

    // return the first location at which 1 can be inserted
    // in Numbers
    // 返回查找元素的第一个可安插位置，也就是“元素值>=查找值”的第一个元素的位置
    location = lower_bound(start, end, 1) ;

    cout << "First location element 1 can be inserted in Numbers is: " << location - start<< endl ;
    //一个数组number序列为：4,10,11,30,69,70,96,100.设要插入数字3,9,111.pos为要插入的位置的下标 则
    //pos = lower_bound( number, number + 8, 3) - number//pos = 0.即number数组的下标为0的位置。
    //int pos = lower_bound( Numbers, Numbers + 8, 3) - Numbers//pos = 0.即number数组的下标为0的位置。
    int pos = lower_bound( start, end, 3) - start;//pos = 0.即number数组的下标为0的位置。
    cout << 3 <<"can be inserted in Numbers at : " <<pos<< endl ;
    pos = lower_bound( start, end, 9) - start;
    cout << 9 <<"can be inserted in Numbers at : " <<pos<< endl ;
    pos = lower_bound( start, end, 111) - start;
    cout << 111 <<"can be inserted in Numbers at : " <<pos<< endl ;

    //pos = lower_bound( number, number + 8, 9) - number// pos = 1，即number数组的下标为1的位置（即10所在的位置）。
    //pos = lower_bound( number, number + 8, 111) - number// pos = 8，即number数组的下标为8的位置（但下标上限为7，所以返回最后一个元素的下一个元素）。

    return 0;
}
