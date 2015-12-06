/*
   A bit of explanation: It works by creating a "selection array" (v), where we place r selectors, then we create all permutations of these selectors, and print the corresponding set member if it is selected in in the current permutation of v. Hope this helps.
   */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
     int n, r;
     cin >> n;
     cin >> r;

     vector<bool> v(n);
     fill(v.begin() + r, v.end(), true);

     do {
          for (int i = 0; i < n; ++i) {
               if (!v[i]) {
                    cout << (i+1) << " ";
               }
          }
          cout << "\n";
     } while (next_permutation(v.begin(), v.end()));
     return 0;
}
