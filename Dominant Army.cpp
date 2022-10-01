#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int a,b,c;
	    cin>>a>>b>>c;
	    if(a>(b+c)){
	        cout<<"yes"<<endl;
	    }
	     else if(b>(a+c)){
	        cout<<"yes"<<endl;
	    }
	     else if(c>(a+b)){
	        cout<<"yes"<<endl;
	    }
	    else{
	        cout<<"No"<<endl;
	    }
	}
}
