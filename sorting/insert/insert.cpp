#include<iostream>
using namespace std;
//直接插入排序
int arr[15]= {11,22,45,71,2,3,5,7,9,0,14,1,4,5,6};
int list [15];

void binaryInsertSort(int arr[],int size) {
    int low,high,temp,value;
    for(int i=0; i<size; i++) {
        value=arr[i];
        low=0;
        high=i-1;
        while(low<=high) {
            temp=(low+high)/2;
            if(list[temp]<value)
                low=temp+1;
            else
                high=temp-1;
        }
        for(int k=i; k>=low; k--) {
            list[k]=list[k-1];
        }
        list[low]=value;
    }
}

void show() {
    for(int j=0; j<15; j++)
        cout<<list[j]<<" ";
    cout<<endl;
}

int main() {
    binaryInsertSort(arr,15);
    cout<<"折半插入后："<<endl;
    show();
}
