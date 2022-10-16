#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr , int m)
{
	reverse(arr.begin()+m+1,arr.end());
    for(int i: arr){
        cout<<i;
    }
    
}

int main(){
    int q,n,m;
    vector<int> v;
    cin>>q;
    while(q!=0){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            int num;
            cin>> num;
            v.push_back(num);
        }
        
        reverseArray(v,m);
        q--;
    }
    
}