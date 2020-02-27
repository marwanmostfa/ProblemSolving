#include <iostream>
#define ll long long int
using namespace std;

int main() {
	ll n;
	cin>>n;
	ll* arr=new ll[n];
	ll* mini=new ll[n];
	ll* maxm=new ll[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	ll mid=arr[(n-1)/2];
	for(int i=0;i<n;i++){
		ll a,b;
		if(i==0){
			a=arr[1]-arr[0];
			b=arr[n-1]-arr[0];
		}
		else if(i==n-1){
			a=arr[n-1]-arr[n-2];
			b=arr[n-1]-arr[0];
		}
		else{
			a=min(arr[i]-arr[i-1],arr[i+1]-arr[i]);
			b=max(arr[n-1]-arr[i],arr[i]-arr[0]);
		}
		mini[i]=a;
		maxm[i]=b;
	}
	
	for(int i=0;i<n;i++){
		cout<<mini[i]<<' '<<maxm[i]<<endl;
	}
	return 0;
}
