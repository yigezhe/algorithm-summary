#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n, r;
  cin >> n;
  cin >> r;

  vector<bool> v(n);
  //fill(v.begin() + n - r, v.end(), true);
  //从尾巴开始的r个是正值！
  fill(v.end() - r, v.end(), true);
  for (int i = 0; i < n; ++i) {
    cout << v[i] << " ";
  }
  cout<<"\n----------"<<endl;

  //这里产生的是有重复元素的排序！
  do {
    for (int i = 0; i < n; ++i) {
      if (v[i]) {
        cout << (i+1) << " ";
      }
    }
    cout << "\n";
  } while (next_permutation(v.begin(), v.end()));
  //这里我需要理解的就是next_permutation是如何实现的，这不是我当前的工作！

  do {
    for (int i = 0; i < n; ++i) {
      cout << v[i] << " ";
    }
    cout << "\n";
  } while (next_permutation(v.begin(), v.end()));

  return 0;
}
