#include <iostream>
#include<stack>
using namespace std;
 
int main() {
	int n;
	stack<int> s;
	cin>>n;
	n=n*2;
	int *arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int stop;
	s.push(arr[1]);
	int in=arr[1];
		for(int i=1;i<(n)-2;i=i+2){
			stop=in-arr[i+1]+arr[i+2];
			in=in-arr[i+1]+arr[i+2];
			s.push(stop);
		}
		int max=s.top();
		while(!s.empty()){
			if(max<s.top()){
				max=s.top();
			}
			s.pop();
		}
		cout<<max;
	return 0;
}
