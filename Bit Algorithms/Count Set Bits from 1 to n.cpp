#include<iostream>
using namespace std;
int CountBitUnit(signed int i){
	if(i<=0)
	return 0;
	return (i%2==0?0:1)+CountBitUnit(i/2);
}
int CountBits(signed int n){
	int result=0;
	for(int i=1;i<=n;i++){
		result+=CountBitUnit(i);
	}
	return result;
}
int main(){
	cout<<"Enter a number:";
	signed int n;
	cin>>n;
	int result=CountBits(n);
	cout<<result<<" bits are set";
	return 0;
}
