#include <iostream>
using namespace std;
 
int main() {
	int in,out;
	cin>>in>>out;
	int* perm=new int[out];
	for(int i=0; i<out; i++) cin>>perm[i];
	if(in>out) cout<<"IMPOSSIBLE";
	else{
		int ans[in];
		int cnt=0;
		for(int i=1; i<=in; i++){
			for(int j=0;j<out;j++){
				if(i==perm[j]){
					ans[i-1]=j+1;
					cnt++;
					break;
				}
			}
		}
		if(cnt>= in){
			for(int i=0; i<in; i++) cout<<ans[i]<<" ";
		}
		else{
			cout<<"IMPOSSIBLE";
		}
	}
	return 0;
}
