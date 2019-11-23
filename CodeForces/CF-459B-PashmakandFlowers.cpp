#include <iostream>
#include <algorithm> 
using namespace std; 
int main() {
	long long n;
	cin>>n;
	long long* arr= new long long[n];
	long long maxCount=0,max=0;
	long long minCount=0,min=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr, arr+n);
	max=arr[n-1];
	min=arr[0];
	int i=0;
	while(i !=n){
		if(arr[i]==min){ minCount++;
			
		}	
		if(arr[n-1-i]==max){
			maxCount++;	
		} 		
		i++;
	}
	long long maximalDiff=max-min;
	long long ways=0;
	if(maximalDiff==0) ways=(n-1)*n/2;
	else ways=maxCount*minCount;
	
	cout<<maximalDiff<<" "<<ways;
	return 0;
}
