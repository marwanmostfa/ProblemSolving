/*Assume you are working in mod(M) arithmetic, what is the additive and multiplicative inverse of N?

Input
The input consists of 1 line that has 2 numbers M, N respectively (1 ≤ M, N ≤ 20000000000000000000000)

Output
In case N has no multiplicative inverse, print "IMPOSSIBLE" without the quotes. Otherwise print 2 numbers which represent the additive and multiplicative inverses respectively of N. All printed numbers must be mod(M) */


#include <iostream>
#include <string>
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
 
string execal(long long m,long long n){
	long long a1,a2,a3,b1,b2,b3,q,t1,t2,t3;
	a1=1;
	a2=0;
	a3=m;
	b1=0;
	b2=1;
	b3=n;
	while(1){
		if(b3==0) {return "IMPOSSIBLE" ;break;}
		else if(b3==1){
			if(b2<0){
				while(b2<0) b2=m+b2;
			}
			return to_string(b2); 
			break;
		}
		q=a3/b3;
		t1=a1-q*b1;
		t2=a2-q*b2;
		t3=a3-q*b3;
		a1=b1;
		a2=b2;
		a3=b3;
		b1=t1;
		b2=t2;
		b3=t3;
	}
}
int main() {
	long long m,n;
	cin>>m>>n;
	if(execal(m,n)=="IMPOSSIBLE") cout<<"IMPOSSIBLE";
	else cout<<(m-n%m)<<" "<<execal(m,n);
	return 0;
}
