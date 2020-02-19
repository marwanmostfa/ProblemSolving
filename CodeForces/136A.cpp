#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int* arr=new int[n];
	int* ans=new int[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i+1==arr[j]) ans[i]=j+1;
		}
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
