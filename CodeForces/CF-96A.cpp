#include <iostream>
#include <string.h>
using namespace std;
 
int main()
{
   
     string s;
     cin>>s;
    int sum=0;
    int counter=0;
     if (s.length() <8){
         cout<<"NO";
     }
     else
    {
        for (unsigned int i=0; i<s.length(); i++)
        {
            for (unsigned int j=i+1; j<i+7; j++)
            {
                if(s[i] == s[j])
                {
                    sum++;
                }
            }
           
            if (sum ==6){
                counter++;
            }
            sum=0;
        }
        
        if(counter >0)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
     
     
     
    }
    return 0;
}
 
 
