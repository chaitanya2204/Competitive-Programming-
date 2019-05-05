//	Chaitanya Aaditya
//	Birla Institute of Technology, Mesra
//	https://codeforces.com/contest/278/problem/C

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

vector<ll> v[mx], adj[mx];
bool vis[mx];
ll ans = 0;

void dfs(ll s)
{
	vis[s] = 1;
	fr(i, adj[s].size())
	{
		if(!vis[adj[s][i]])
			dfs(adj[s][i]);
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

	ll n, m;
	cin >> n >> m;
	ll cnt = 0;
	fr1(i, n)
	{
		ll k;
		cin >> k;
		if(k == 0)	cnt++;
		fr1(j, k)
		{
			ll x;
			cin >> x;
			v[x].pb(i);
		}
	}
	fr1(i, m)
	{
		if(v[i].size() > 1)
		{
			fr(j, v[i].size())
			{
				for(ll ii=j+1; ii<v[i].size(); ii++)
				{
					adj[v[i][j]].pb(v[i][ii]);
					adj[v[i][ii]].pb(v[i][j]);
				}
			}
		}
	}
	fill(vis, 0);
	fr1(i, n)
	{
		if(!vis[i])
		{
			ans++;
			dfs(i);
		}
	}
	if(cnt == n)
	{
		cout << ans << "\n";
		return 0;
	}
	cout << ans - 1 << "\n";

	return 0;
}