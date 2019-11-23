#include <iostream>
#include<math.h>
 
using namespace std;
 
int main()
{
   int n ,k,counter=0;
   int x[2];
   for (int i=0; i<2; i++)
   {
       cin>>x[i];
   }
   n=x[0];
   k=x[1];
   int * ptr;
   ptr=new int[n];
   if (k==n);
   k--;
   for(int i=0; i<n; i++)
    {
            cin>>ptr[i];
    }
    
    for(int i=0; i<n; i++)
    {
            if(ptr[i] >= ptr[k] && (ptr[i] >0))
            counter++;
            else
            counter=counter+0;
            
    }
        cout<<counter;
       
    return 0;
}
