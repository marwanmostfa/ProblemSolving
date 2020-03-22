#include <iostream>
using namespace std;
 
int main() {
	int n;
	cin>>n;
	char k;
	cin>>k;
	string* arr=new string[n];
	int cnt=0;
	
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=0;i<n;i++){
		int t=k-'0';
		bool flag[t+1]={false};
		bool flag2=true;
		for(int j=0;j<arr[i].length();j++){
			if(arr[i][j]<=k ){
				flag[arr[i][j]-'0']=true;
			}
		}
		for(int w=0;w<=t;w++){
			if(!flag[w]){flag2=false;
			}
		}
		if(flag2)cnt++;
	}
	cout<<cnt;
	return 0;
}
