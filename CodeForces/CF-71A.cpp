#include <iostream>
#include<string.h>
 
 
using namespace std;
 
int main()
{
    int n;
    string *s=NULL;
    cin>>n;
    s=new string[n];
  for(int i=0; i<n;i++)
  {
      cin>>s[i];
  }
  
  for (int i=0; i<n;i++)
  {
      if(s[i].length() <=10)
      {
          cout<<s[i]<<endl;
      }
      else
      {
          cout<<s[i][0]<<s[i].length()-2<<s[i][s[i].length()-1] <<endl;
      }
  }
  delete[]s;
        
    return 0;
}
