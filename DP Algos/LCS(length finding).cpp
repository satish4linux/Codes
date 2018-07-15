#include<bits/stdc++.h>
using namespace std;
int sol[1000][1000];
int LCS(string a,string b,int x,int y);
void PrintLCS(string a,string b);
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a,b;
	cin>>a>>b;
	int x=a.size();
	int y=b.size();
	//cout<<x<<" "<<y;
	int l=LCS(a,b,x,y);
	cout<<"Length of longest common subsequence is:"<<l;
	return 0;
}
int LCS(string a,string b,int x,int y){
	//cout<<a<<" "<<b<<"\n";
	for(int i=0;i<=x;i++){
		for(int j=0;j<=y;j++){
			if(i==0 || j==0){
				sol[i][j]=0;
			}
			else if(a[i-1]==b[j-1]){
				sol[i][j]=1+sol[i-1][j-1];
				//cout<<"["<<i<<"]["<<j<<"]="<<sol[i][j]<<"\n";
			}
			else
				sol[i][j]=max(sol[i][j-1],sol[i-1][j]);
		}
	}
	
	for(int i=0;i<=x;i++){
		for(int j=0;j<=y;j++){
			cout<<sol[i][j]<<" ";
		}
		cout<<"\n";
	}
	PrintLCS(a,b);
	return sol[x][y];
}
void PrintLCS(string a,string b){
	int x=a.size();
	int y=b.size();
	bool flag=false;
	std::vector<char> v;
	for(int i=x;i>=0;){
		for(int j=y;j>=0;){
			if(i==0 || j==0){
				flag=true;
				break;
			}
			else if(a[i-1]==b[j-1]){
				cout<<a[i-1];
				i--;
				j--;
			}
			else{
				(sol[i][j-1]>=sol[i-1][j])?(j--):(i--);
			}
		}
		if(flag==true)
			break;
	}
	vector <char> :: reverse_iterator it;
	for(it=v.rbegin();it!=v.rend();++it){
		cout<<*it;
	}
	cout<<"\n";
}