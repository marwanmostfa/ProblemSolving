#include <iostream>
using namespace std;
bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to n-1 
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 
int main() {
	int n;
	cin>>n;
	for(int i=1;i<=1000;i++){
		if(!isPrime(n*i+1)){
			cout<<i;
			break;
		}
	}
	return 0;
}
