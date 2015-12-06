#include <iostream>
#include <algorithm>
using namespace std;

void _merge_sort(int a[], int b[], int low, int mid, int high) {
    int k = low;
    int begin1 = low;
    int end1 = mid;
    int begin2 = mid;
    int end2 = high;
    while (begin1 < end1 && begin2 < end2)
        b[k++] = a[begin1] < a[begin2] ? a[begin1++] : a[begin2++];
    copy(&a[begin1], &a[end1], &b[k]);
    copy(&a[begin2], &a[end2], &b[k]);
}
void merge_sort(int arr[], int len) {
    int* a = arr;
    int* b = new int[len];
    for (int seg = 1; seg < len; seg += seg) {
        for (int start = 0; start + seg <= len; start += seg + seg)
            _merge_sort(a, b, start, start + seg, min(start + seg + seg, len));
        swap(a, b);
    }
    if (a != arr) {
        copy(a, &a[len], b);
        b = a;
    }
    delete[] b;
}

int main() {
    int a[] = { 57, 22, 34, 84, 32, 82, 55, 91, 87, 13 };
    int len = sizeof(a) / sizeof(*a);
    merge_sort(a, len);
    for (int i = 0; i < len; i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
