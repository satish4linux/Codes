
// Note : This Cyphering algorithm is meant to deal with only alphabets of lower or upper case excluding the symbols and the special characters


#include<iostream>
#include<string>
#include<vector>
using namespace std;
	char arr[5][5]={
		{'L','G','D','B','A'},{'Q','M','H','E','C'},{'U','R','N','I','F'},{'X','V','S','O','K'},{'Z','Y','W','T','P'}
	};


// Algorithm for finding the position of the alphabet

vector<int> find_pos(char a){
	vector <int> v;
	if(islower(a))
		a=toupper(a);
	int i,x,y;
	bool flag=false;
	for(i=4;i>0;i--){
		if(a==arr[0][i]){
			v.push_back(0);
			v.push_back(i);
			return v;
		}
		else if(a>arr[0][i] && a<arr[0][i-1]){
			flag=true;
			x=0;
			y=i;
			break;
		}
		else
			continue;
	}

	int j;
	if(flag==false){
		for(j=0;j<4;j++){
			if(a==arr[j][0]){
				v.push_back(j);
				v.push_back(0);
				return v;
			}
			else if(a>arr[j][0] && a<arr[j+1][0]){
				x=j;
				y=0;
				break;
			}
		}
	}

	for(i=x,j=y;i<=4-y,j<=4-x;i++,j++){
		if(a=='I' || a=='J'){
			if(arr[i][j]=='I' || arr[i][j]=='J'){
				v.push_back(i);
				v.push_back(j);
				return v;
			}
		}
		else{
			if(arr[i][j]==a){
				v.push_back(i);
				v.push_back(j);
				return v;
			}
		}
	}

}	

// Playfair Cyphering algorithm

string Playfair(string str){
	vector <char> v;
	int count=0;
	for(int i=0;i<str.size();i++){
		if(str[i]!=' ')
			count++;
	}
	if(count%2!=0)
		str.append("z");

	int x1,y1,x2,y2;
	int x,y,j;
	for(int i=0;i<str.size()-1;){
		j=i+1;
		if(str[i]==' '){
			v.push_back(' ');
			i++;
			continue;
		}
		if(str[j]==' '){
			v.push_back(' ');
			j++;
		}
		vector <int> a=find_pos(str[i]);
		x1=a[0];
		y1=a[1];
		a=find_pos(str[j]);
		x2=a[0];
		y2=a[1];
		if(x1==x2){
			if(y1<4)
				v.push_back(arr[x1][y1+1]);
			else
				v.push_back(arr[x1][0]);
			if(y2<4)
				v.push_back(arr[x2][y2+1]);
			else
				v.push_back(arr[x2][0]);
		}
		else if(y1==y2){
			if(x1<4)
				v.push_back(arr[x1+1][y1]);
			else
				v.push_back(arr[0][y1]);
			if(x2<4)
				v.push_back(arr[x2+1][y2]);
			else
				v.push_back(arr[0][y2]);
		}
		else{
			v.push_back(arr[x1][y2]);
			v.push_back(arr[x2][y1]);
		}
		i=j+1;
	}

	string res(v.begin(),v.end());
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string in_text;
	getline(cin,in_text);
	string out_text=Playfair(in_text);
	cout<<out_text;
	return 0;
}