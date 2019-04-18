//	Chaitanya Aaditya
//	Birla Institute of Technology, Mesra

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
const ll mx = 2e5 + 5;

ll n, k;
vector<ll> adj[mx];
ll dp[50005][505], ans = 0;

void dfs(ll u, ll p)
{
	dp[u][0] = 1;
	fr(i, adj[u].size())
	{
		ll curr = adj[u][i];
		if(curr == p)
			continue;
		dfs(curr, u);
		fr(j, k)
			ans += dp[u][j]*dp[curr][k-1-j];
		fr1(j, k)
			dp[u][j] += dp[curr][j-1];
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	fr(i, n-1)
	{
		ll x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	//fill(dp, 0);
	dfs(1, 0);
	cout << ans << "\n";

	return 0;
}