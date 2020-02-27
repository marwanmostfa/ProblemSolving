#include <iostream>
using namespace std;
 
int main() {
	string s="qwertyuiopasdfghjkl;zxcvbnm,./";
	char c;
	cin>>c;
	string t;
	cin>>t;
	string ans=" ";
	for(int i=0;i<t.length();i++){
		for(int j=0;j<s.length();j++){
			if(t[i]==s[j]){
				if(c=='R') ans+=s[j-1];
				else ans+=s[j+1];
			}
		}
	}
	cout<<ans;
	return 0;
}
