#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int* arr=new int[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int m;
	cin>>m;
	int* x=new int[m];
	int* y=new int[m];
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		x[i]=a; y[i]=b;
	}
	
	for(int i=0;i<m;i++){
		if(x[i]==1){
			arr[1]=arr[1]+arr[0]-y[i];
			arr[0]=0;
		}
		else if(x[i]==n){
			arr[n-2]=arr[n-2]+y[i]-1;
			arr[n-1]=0;
		}
		else{
			arr[x[i]]=arr[x[i]]+arr[x[i]-1]-y[i];
			arr[x[i]-2]=arr[x[i]-2]-1+y[i];
			arr[x[i]-1]=0;
		}
	}
		for(int i=0;i<n;i++){
			cout<<arr[i]<<endl;
		}
	return 0;
}
