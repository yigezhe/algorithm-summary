/*
   I assume you're asking about combinations in combinatorial sense (that is, order of elements doesn't matter, so [1 2 3] is the same as [2 1 3]). The idea is pretty simple then, if you understand induction / recursion: to get all K-element combinations, you first pick initial element of a combination out of existing set of people, and then you "concatenate" this initial element with all possible combinations of K-1 people produced from elements that succeed the initial element.

   As an example, let's say we want to take all combinations of 3 people from a set of 5 people. Then all possible combinations of 3 people can be expressed in terms of all possible combinations of 2 people:

   comb({ 1 2 3 4 5 }, 3) =
   { 1, comb({ 2 3 4 5 }, 2) } and
   { 2, comb({ 3 4 5 }, 2) } and
   { 3, comb({ 4 5 }, 2) }
   Here's C++ code that implements this idea:
   */
#include <iostream>
#include <vector>

using namespace std;

vector<int> people;
vector<int> combination;

void pretty_print(const vector<int>& v) {
     static int count = 0;
     cout << "combination no " << (++count) << ": [ ";
     for (int i = 0; i < v.size(); ++i) { cout << v[i] << " "; }
     cout << "] " << endl;
}

void go(int offset, int k) {
     if (k == 0) {
          pretty_print(combination);
          return;
     }
     for (int i = offset; i <= people.size() - k; ++i) {
          combination.push_back(people[i]);
          go(i+1, k-1);
          combination.pop_back();
     }
}

int main() {
     int n = 5, k = 3;

     for (int i = 0; i < n; ++i) { people.push_back(i+1); }
     go(0, k);

     return 0;
}
