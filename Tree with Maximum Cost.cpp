#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll n;
const ll mx = 2e5 + 5;
ll a[mx], level[mx], ans[mx], summ[mx];
bool vis[mx];
vector<ll> adj[mx];

void dfs(ll s)
{
	if(vis[s])
		return;
	vis[s] = true;
	for(ll i=0; i<adj[s].size(); i++)
	{
		if(!vis[adj[s][i]])
		{
			level[adj[s][i]] = level[s] + 1;
			dfs(adj[s][i]);
		}
	}
}

ll DFS(ll s)
{
	if(vis[s])
		return -1;
	vis[s] = true;
	ll sum = 0;
	for(ll i=0; i<adj[s].size(); i++)
	{
		if(!vis[adj[s][i]])
		{
			sum += (level[adj[s][i]] * a[adj[s][i]]) + summ[s];
			summ[adj[s][i]] = DFS(adj[s][i]);
		}
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(ll i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	for(ll i=1; i<=n-1; i++)
	{
		ll x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(ll i=1; i<=n; i++)
	{
		memset(level, 0, sizeof level);
		memset(vis, 0, sizeof vis);
		level[i] = 0;
		dfs(i);
// 		for(ll i=1; i<=n; i++)
// 		{
// 		    cout << level[i] << " ";
// 		}
// 		cout << "\n";
		memset(vis, 0, sizeof vis);
		ans[i] = DFS(i);
	}
	ll anss = -1e18;
	for(ll i=1; i<=n; i++)
	{
	    cout << ans[i] << " ";
		anss = max(anss, ans[i]);
	}
	cout << "\n";
	cout << anss << "\n";
	return 0;
}