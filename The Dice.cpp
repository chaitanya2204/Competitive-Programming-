#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    string s;
    cin >> s;
    if(s[s.size()-1] == '6')
    {
        cout << "-1\n";
        return 0;
    }
    ll ans = 0;
    for(ll i=0; i<s.size(); i++)
    {
        if(s[i] != '6')
            ans++;
    }
    cout << ans << "\n";
    return 0;
}