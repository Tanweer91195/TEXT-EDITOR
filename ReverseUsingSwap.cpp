#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;
    for(int i=1;i<mid;i++){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}