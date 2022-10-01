#include <iostream>
using namespace std;

int main() {
	int testcase;
	cin>>testcase;
	while(testcase--){
	    int price;
	    cin>>price;
	    if(price<=100){
	        price=price-0;
	    }
	    else if((price>100)&&(price<=1000)){
	        price=price-25;
	    }
	    else if((price>1000)&&(price<=5000)){
	        price=price-100;
	        
	    }
	    else if(price>5000){
	        price=price-500;
	    }
	    cout<<price<<endl;
	}
	return 0;
}
