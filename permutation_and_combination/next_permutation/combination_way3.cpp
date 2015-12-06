#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main(void) {

    int n=5, k=3;

    // vector<vector<int> > combinations;
    vector<int> selected;
    vector<int> selector(n);
    fill(selector.begin(), selector.begin() + k, 1);
    do {
        for (int i = 0; i < n; i++) {
            if (selector[i]) {
                selected.push_back(i);
            }
        }
        //     combinations.push_back(selected);
        //do_sth(selected);
        //这是一个新式用法！可以直接打印一个vector！
        copy(selected.begin(), selected.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
        selected.clear();
    } while (prev_permutation(selector.begin(), selector.end()));

    return 0;
}
