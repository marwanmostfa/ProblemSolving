#include <iostream>
#include<bits/stdc++.h> 
using namespace std;
char *removeDuplicate(char str[], int n) 
{  
    set<char>s (str, str+n); 
    int i = 0; 
    for (auto x : s) 
       str[i++] = x; 
    str[i] = '\0';   
    return str; 
}  
int main() {
	int n;
	cin>>n;
	char s[n];
	for(int i=0;i<n ;i++){
		char c;
		cin>>c;
		s[i]=tolower(c);}
		int cc=sizeof(s) / sizeof(s[0]); 

	if(n<26) cout<<"NO";
	else{
		string r=removeDuplicate(s,n);
		if(r.length()<26)cout<<"NO";
		else cout<<"YES";
	}
	
	return 0;
}
