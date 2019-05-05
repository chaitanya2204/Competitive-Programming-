//	Chaitanya Aaditya
//	Birla Institute of Technology, Mesra
//	https://codeforces.com/contest/268/problem/C

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
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

	ll n, m;
	cin >> n >> m;
	cout << min(n, m) + 1 << "\n";
	ll i = n, j = 0;
	while(j<=m and i>=0)
	{
		cout << i << " " << j << "\n";
		i--, j++;
	}

	return 0;
}