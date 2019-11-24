#include <iostream>
#include<math.h>
 
using namespace std;
 
int main()
{
   unsigned long long int n,m,a,l,w;
    unsigned long long int x[3];
   unsigned long long int result=0;
  for(int i=0; i<3;i++)
  {
      cin>>x[i];
  }
  n=x[0];
  m=x[1];
  a=x[2];
  
  l=((n%a)!=0)? (n/a)+1: (n/a);
  w=((m%a)!=0)? (m/a)+1: (m/a);
  result=l*w;
 
  cout<<result;
        
    return 0;
}
