#include <iostream>
using namespace std;
 
int main() {
	long long N;
	cin>>N;
	string s;
	cin>>s;
	string r="";
	for(int i=0; i<s.length(); i++){
		r=r+char((s[i]+N-65)%26+65);
	
	}
	cout<<r;
	return 0;
}
