#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    string s;
    cin >> s;
    ll pre = 0, ans = 0;
    for(ll i=0; i<s.size()-1; i++)
    {
        if(s[i] != s[i+1])
            pre++, ans = max(pre, ans);
        else
            pre = 0;
    }
    cout << ans + 1 << "\n";
}