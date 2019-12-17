#include <iostream>
#include <stdio.h>
using namespace std;
long long exponentMod(long long A, long long B, long long C) 
{ 
    // Base cases 
    if (A == 0) 
        return 0; 
    if (B == 0) 
        return 1; 
  
    // If B is even 
    long long y; 
    if (B % 2 == 0) { 
        y = exponentMod(A, B / 2, C); 
        y = (y * y) % C; 
    } 
  
    // If B is odd 
    else { 
        y = A % C; 
        y = (y * exponentMod(A, B - 1, C) % C) % C; 
    } 
  
    return (long long)((y + C) % C); 
} 
int main() {
	long long a,b,c;
	cin>>a>>b>>c;
	cout<<exponentMod(a,b,c);
	return 0;
}
