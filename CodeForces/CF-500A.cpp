//New year transportation problem
#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define ll long long
int main()
{
    ll n , t;
    cin >> n >> t;
    ll a[n];
    for(ll i = 0 ; i < n ; i++)
        cin >> a[i];
    ll i = 1;
    bool flag = false;
    while(i <= n)
    {
        if(i == t)
        {
            flag = true;
            break;
        }
        if(i > t)
            break;
        i+=a[i-1];
    }
    cout << ((flag)?"YES":"NO");
    return 0;
}
