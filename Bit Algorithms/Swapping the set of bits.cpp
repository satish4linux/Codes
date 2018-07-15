#include<iostream>
using namespace std;
int main(){
	int x,i,j,n;
	cin>>x>>i>>j>>n;
	int val_1,val_2;
	val_1=(x>>i)&((1<<n)-1);
	val_2=(x>>j)&((1<<n)-1);
	int xor_1=val_1 ^ val_2;
	xor_1=(xor_1<<i)|(xor_1<<j);
	x=x ^ xor_1;
	cout<<x<<" is the required number after swapping the bits";
	return 0;
}
