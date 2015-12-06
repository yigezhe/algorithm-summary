/*http://blog.csdn.net/renwenchao888/article/details/6513385*/
#include <conio.h>
#include <iostream>
using namespace std;
// 首先 要求皇后不冲突，那么每行只应该有一个皇后
// 用queens[]数组在存储每个皇后的位置
// 例如: queens[m] = n 表示 第m行的皇后放在第n列上
#define MAX 8
int sum = 0;
class QueenPuzzle
{
 int queens[MAX]; // 存储每行皇后的列标
 
public:
 void printOut(); // 打印结果
 int IsValid(int n); //判断第n个皇后放上去之后，是否合法
 void placeQueen(int i); // 递归算法 放置皇后
};
void QueenPuzzle::printOut()
{
 for(int i=0; i<MAX; i++)
 {
  for(int j=0; j<MAX; j++)
  {
   if(j == queens[i])
    cout << "Q ";
   else
    cout << "0 ";
  }
  cout << endl;
 }
 cout << endl << "按q键盘退出，按其他键继续" << endl << endl;
 
 if(getch() == 'q')
  exit(0);
}
// 在第i行放置皇后
void QueenPuzzle::placeQueen(int i)
{
 for(int j=0; j<MAX; j++)
 {
  // 如果全部放完了 输出结果
  if(i == MAX)
  {
   sum ++;
   cout << "第" << sum << "组解:" << endl;
   printOut();
   
   return;
  }
  // 放置皇后
  queens[i] = j;
  // 此位置不能放皇后 继续试验下一位置
  if(IsValid(i))
   placeQueen(i+1);
 }
}
//判断第n个皇后放上去之后，是否合法，即是否无冲突 
int QueenPuzzle::IsValid(int n) 
{ 
 //将第n个皇后的位置依次于前面n－1个皇后的位置比较。 
 for(int i = 0 ; i < n ; i++) 
 { 
  //两个皇后在同一列上，返回0 
  if(queens[i] == queens[n]) 
   return 0;
  //两个皇后在同一对角线上，返回0 
  if(abs(queens[i] - queens[n]) == (n - i)) 
   return 0; 
 }
 //没有冲突，返回1。
 return 1; 
}
void main()
{
 QueenPuzzle queen;
 queen.placeQueen(0);
 cout << "共" << sum << "组解" << endl;
}

