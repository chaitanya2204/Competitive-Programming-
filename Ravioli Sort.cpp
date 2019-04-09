//	Chaitanya Aaditya
//	Birla Institute of Technology, Mesra
//	https://codeforces.com/contest/952/problem/C

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define fill(ar, x) memset(ar, x, sizeof ar)
#define fr(i, n) for(ll i=0; i<n; i++)
#define fr1(i, n) for(ll i=1; i<=n; i++)
const ll inf = 1e18;
const ll mod = 998244353;
const ll mx = 3e5 + 5;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;
	ll a[n];
	fr(i, n)	cin >> a[i];
	fr(i, n-1)
	{
		if(abs(a[i+1]-a[i]) >= 2)
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";

	return 0;
}