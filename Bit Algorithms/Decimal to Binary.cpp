#include<iostream>
#include<stack>
using namespace std;
int main(){
	stack <int> s;
	int n;
	string str="0";
	cout<<"Enter a decimal number:";
	cin>>n;
	while(n!=0){
		s.push((n&1));
		n=n>>1;
	}
	while(!s.empty()){
		int t=s.top();
		cout<<t;
		s.pop();
	}
	return 0;
}
