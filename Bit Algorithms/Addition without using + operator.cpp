#include<iostream>
using namespace std;
int main(){
	signed int x,y;
	cin>>x>>y;
	int c;
	while(y!=0){
		c=x&y;
		x=x^y;
		y=c<<1;
	}
	cout<<"Sum is:"<<x;
	return 0;
}
