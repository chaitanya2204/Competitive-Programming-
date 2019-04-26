//	Chaitanya Aaditya
//	Birla Institute of Technology, Mesra
//	https://codeforces.com/problemset/problem/999/E

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

ll n, m, s, cnt = 0;
vector<ll> adj[mx];
bool vis[mx], vis1[mx];
vector<pair<ll,ll> > v;

void dfs(ll s)
{
	vis[s] = 1;
	fr(i, adj[s].size())
	{
		if(!vis[adj[s][i]])
			dfs(adj[s][i]);
	}
}

void dfs1(ll s)
{
	vis1[s] = 1;
	cnt++;
	fr(i, adj[s].size())
	{
		if(!vis[adj[s][i]] and !vis1[adj[s][i]])
			dfs1(adj[s][i]);
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

	cin >> n >> m >> s;
	s--;
	fr(i, m)
	{
		ll x, y;
		cin >> x >> y;
		x--, y--;
		adj[x].pb(y);
		//adj[y].pb(x);
	}
	fill(vis, 0);
	dfs(s);
	fr(i, n)
	{
		if(!vis[i])
		{
			cnt = 0;
			fill(vis1, 0);
			dfs1(i);
			v.pb({cnt, i});
		}
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	ll ans = 0;
	fr(i, v.size())
	{
		if(!vis[v[i].ss])
			ans++,	dfs(v[i].ss);
	}
	cout << ans << "\n";

	return 0;
}