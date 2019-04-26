#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
const ll mx = 1e5 + 5;

vector<ll> adj[mx];
bool vis[mx], color[mx];
ll n;

void dfs(ll i, ll col)
{
	if(vis[i])
		return;
	vis[i] = 1;
	color[i] = col;
	for(auto it : adj[i])
	{
		if(!vis[it])
			dfs(it, col^1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(ll i=0; i<n-1; i++)
	{
		ll x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(ll i=0; i<n; i++)
	{
		if(!vis[i])
			dfs(i, 0);
	}
	ll cnt=0;
	for(ll i=1; i<=n; i++)
	{
		if(color[i])
			cnt++;
	}
	cout << cnt*(n-cnt) - n + 1 << "\n";

	return 0;
}