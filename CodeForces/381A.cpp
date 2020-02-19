#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int* arr=new int[n];
	for(int i=0;i<n ;i++){
		cin>>arr[i];
	}
	int s=0,w=0;
	int d=0;
	int*p1=arr;
	int*p2=(arr+n-1);
	for(int i=0;i<n || p1==p2 ;i++){
		if(*p1>*p2){
			w=*p1;
			p1=p1+1;
		}
		else{
			w=*p2;
			p2=p2-1;
		}		
		if(i==0 || i%2==0) s+=w;
		else d+=w;
	}	
	cout<<s<<' '<<d;
	
	return 0;
}
