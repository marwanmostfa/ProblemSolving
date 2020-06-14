#include <iostream>
using namespace std;
 
int main() {
	long long k,n,w;
	cin>>k>>w>>n;
	long long sum=n*(n+1)/2;
	long long total=sum*k;
	if(w>=total)cout<<0;
	else{
		cout<<total-w;
	}
	return 0;
}
