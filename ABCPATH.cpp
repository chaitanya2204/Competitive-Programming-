//	Chaitanya Aaditya
//	Birla Institute of Technology, Mesra

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
const ll mx = 1e5 + 5;

ll n, m;
string s[55];
ll dis[55][55];

bool ok(ll i, ll j)
{
	if(i<0 or j>=m)
		return 0;
	return 1;
}

void dfs(ll i, ll j, ll dist)
{
	dis[i][j] = dist + 1;
	if(ok(i+1, j) and s[i][j]+1==s[i+1][j] and dis[i+1][j] < 1 + dis[i][j])
		dfs(i+1, j, dis[i][j]);
	if(ok(i-1, j) and s[i][j]+1==s[i-1][j] and dis[i-1][j] < 1 + dis[i][j])
		dfs(i-1, j, dis[i][j]);
	if(ok(i, j+1) and s[i][j]+1==s[i][j+1] and dis[i][j+1] < 1 + dis[i][j])
		dfs(i, j+1, dis[i][j]);
	if(ok(i, j-1) and s[i][j]+1==s[i][j-1] and dis[i][j-1] < 1 + dis[i][j])
		dfs(i, j-1, dis[i][j]);
	if(ok(i-1, j-1) and s[i][j]+1==s[i-1][j-1] and dis[i-1][j-1] < 1 + dis[i][j])
		dfs(i-1, j-1, dis[i][j]);
	if(ok(i+1, j+1) and s[i][j]+1==s[i+1][j+1] and dis[i+1][j+1] < 1 + dis[i][j])
		dfs(i+1, j+1, dis[i][j]);
	if(ok(i-1, j+1) and s[i][j]+1==s[i-1][j+1] and dis[i-1][j+1] < 1 + dis[i][j])
		dfs(i-1, j+1, dis[i][j]);
	if(ok(i+1, j-1) and s[i][j]+1==s[i+1][j-1] and dis[i+1][j-1] < 1 + dis[i][j])
		dfs(i+1, j-1, dis[i][j]);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t = 0;
	while(1)
	{
		cin >> n >> m;
		if(n == 0 and m == 0)
			return 0;
		t++;
		for(ll i=0; i<n; i++)
		{
			cin >> s[i];
		}
		memset(dis, 0, sizeof dis);
		for(ll i=0; i<n; i++)
		{
			for(ll j=0; j<m; j++)
			{
				if(s[i][j] == 'A' and dis[i][j] == 0)
				{
					dfs(i, j, 0);
				}
			}
		}
		ll ans = -1;
		for(ll i=0; i<n; i++)
		{
			for(ll j=0; j<m; j++)
			{
				ans = max(ans, dis[i][j]);
			}
		}
		cout << "Case " << t << ": " << ans << "\n";
	}

	return 0;
}