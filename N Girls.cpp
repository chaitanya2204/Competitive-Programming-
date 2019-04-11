#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n, k, p, q, ans = 0;
    cin >> n >> k >> p >> q;
    ll a[n];
    for(ll i=0; i<n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);
    ll idx = 0;
    for(ll i=0; i<n; i++)
    {
        while(a[i]*q > a[idx]*p)
            idx++;
        ans = max(ans, min(n, i+1-idx+k));
    }
    cout << ans << "\n";

    return 0;
}