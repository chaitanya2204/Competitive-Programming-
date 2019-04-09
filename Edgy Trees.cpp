//	Chaitanya Aaditya
//	Birla Institute of Technology, Mesra
//	https://codeforces.com/contest/1139/problem/C

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
const ll mx = 3e5 + 5;

ll n, k, sizes[mx];
vector<ll> adj[mx];
bool vis[mx];

ll power(ll a, ll b)
{
	ll ret = 1;
	while(b)
	{
		if(b&1)
		{
			ret *= a;
			ret %= mod;
		}
		a *= a;
		a %= mod;
		b >>= 1;
	}
	return ret;
}

ll dfs(ll u)
{
	vis[u] = 1;
	ll ret = 0;
	fr(i, adj[u].size())
		if(!vis[adj[u][i]])
			ret += dfs(adj[u][i]);
	return ret + 1;
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
	ll x, y, z;
	fr(i, n-1)
	{
		cin >> x >> y >> z;
		if(z == 1)
			continue;
		adj[x].pb(y), adj[y].pb(x);
	}
	fill(vis, 0);
	x = 0, y = 0;
	fr1(i, n)
	{
		if(vis[i])
			continue;
		y = dfs(i);
		x += power(y, k);
		x %= mod;
	}
	z = (power(n, k) - x + mod);
	z %= mod;
	cout << z << "\n";

	return 0;
}