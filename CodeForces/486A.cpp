#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
	long long n,sum=0,t;
	cin>>n;
	if(n%2==0) cout<<n/2;
	else{
		cout<<-((n/2)+1);
	}
	return 0;
}
