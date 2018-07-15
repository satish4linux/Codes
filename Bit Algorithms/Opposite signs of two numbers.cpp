#include<iostream>
using namespace std;
bool Signed(signed int x,signed int y){
	return ((x^y)<0);
}
int main(){
	signed int x,y;
	cout<<"Enter two signed integers:";
	cin>>x>>y;
	if(Signed(x,y)){
		cout<<"Have opposite signs";
	}
	else{
		cout<<"Have same signs";
	}
	return 0;
}
