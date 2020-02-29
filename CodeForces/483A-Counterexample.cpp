#include <iostream>
#include<bits/stdc++.h> 
#define ll long long
using namespace std;
ll gcd(ll a, ll b) 
{ 
    if (!a) 
       return b; 
    return gcd(b%a,a); 
} 
bool coprime(ll a, ll b) { 
      
    if ( gcd(a, b) == 1) 
        return true;  
    else
        return false;         
} 

int main() {
	unsigned ll l,r;
	cin>>l>>r;
	unsigned ll a,b,c;
	bool f1=false;
	bool f2=false;
	for(ll i=l;i<r;i++){
		for(ll j=i+1;j<r;j++){
			for(ll k=j+1;k<=r;k++){
			if(coprime(i,j)&& coprime(j,k) && !coprime(i,k)){
				a=i;
				b=j;
				c=k;
				f1=true;
				break;
			
				}
			}
			if(f1){
				f2=true;	
				break;}
				
		}
		if(f2)break;
	}

	if(f1&&f2){
		cout<<a<<" "<<b<<" "<<c;}
	else cout<<-1;
	return 0;
}
