#include <iostream>
using namespace std;
 
int main() {
	int n,k;
	cin>>n>>k;
	string ans="";
	for(int i=0;i<k;i++){
		char c=97+i;
		ans +=c;
	}
	if(ans.length()<n){
		int j=0;
		int g=ans.length();
		while(ans.length()<n ){
			ans+=ans[j];
			j++;
			if(j==g)j=0;
		}
	}
	cout<<ans;
	return 0;
}
