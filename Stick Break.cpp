#include <bits/stdc++.h>
using namespace std;


void evaluation(int a,int b){
   if(a%b){
       cout<<1<<endl;
   } 
   else{
       cout<<0<<endl;
   }
}

int main() {
	int test;
	cin>>test;
	while(test--){
	    int a,b;
	    cin>>a>>b;
	  evaluation(a,b);
	}
	return 0;
}
