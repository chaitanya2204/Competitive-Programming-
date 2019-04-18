//	Chaitanya Aaditya
//	Birla Institute of Technology, Mesra
//	https://www.spoj.com/problems/BADXOR/

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
const ll mod = 1e9 + 7;
const ll mx = 1025;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t, n, m, k = 0, a[mx], b[mx], dp[mx][mx];
	bool vis[mx];
	cin >> t;
	while(t--)
	{
		fill(vis, 0);
		k++;
		cin >> n >> m;
		fr1(i, n)	cin >> a[i];
		fr1(i, m)	cin >> b[i];
		fill(dp, 0);
		dp[0][0] = 1;
		fr1(i, n)
		{
			fr(j, mx)
			{
				dp[i][j] = (dp[i-1][j] + dp[i-1][a[i]^j]) % mod;
			}
		}
		fr1(i, m)
		{
			vis[b[i]] = 1;
		}
		ll cnt = 0;
		fr(i, mx)
			if(vis[i])
				cnt = (cnt + dp[n][i]) % mod;
		ll tot = 1;
		fr1(i, n)
			tot = (tot << 1) % mod;
		cout << "Case " << k << ": " <<  (tot-cnt+mod)%mod << "\n";
	}	

	return 0;
}