#include <iostream>
using namespace std;
long long gcd(long long x, long long y) 
{ 
    if (x == 0) 
       return y; 
    if (y == 0) 
       return x; 
 
    if (x == y) 
        return x; 
 
    if (x > y) 
        return gcd(x-y, y); 
    return gcd(x, y-x); 
} 
int main() {
	long long a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}
