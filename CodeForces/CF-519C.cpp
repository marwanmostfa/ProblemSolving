#include <iostream>
using namespace std;

int main() {
	long long n,m;
	cin>>n>>m;
	
	long long res=0;
	if( (n>m/2 && m>n/2) || n==m){
	res=(n+m)/3;
	}
	else{
		if(n<=m/2) res=n;
		else res=m;
	}
	
		cout<<res;
	
	return 0;
}
