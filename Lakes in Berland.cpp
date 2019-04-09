//	Chaitanya Aaditya
//	Birla Institute of Technology, Mesra

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

ll n, m, k, cnt = 0;
string a[55];
bool vis[55][55];
vector<pair<ll, pair<ll,ll> > >sizes;

bool ok(ll i, ll j)
{
	if(vis[i][j])
		return false;
	if(i < 1 or j < 1 or i > n-1 or j > m-1)
		return false;
	if(a[i][j] == '.')
		return true;
	return false;
}

void dfs1(ll i, ll j)
{
	if(vis[i][j])
		return;
	vis[i][j] = true;
	a[i][j] = '*';
	if(ok(i, j+1))	a[i][j+1] = '*', dfs1(i, j+1);
	if(ok(i, j-1))	a[i][j-1] = '*', dfs1(i, j-1);
	if(ok(i+1, j))	a[i+1][j] = '*', dfs1(i+1, j);
	if(ok(i-1, j))	a[i-1][j] = '*', dfs1(i-1, j);
}

ll dfs(ll i, ll j)
{
	if(vis[i][j])
		return 0;
	ll ret = 1;
	vis[i][j] = true;
	if(ok(i, j+1))	ret += dfs(i, j+1);
	if(ok(i, j-1))	ret += dfs(i, j-1);
	if(ok(i+1, j))	ret += dfs(i+1, j);
	if(ok(i-1, j))	ret += dfs(i-1, j);
	return ret;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	fr(i, n)	cin >> a[i];
	fr(i, n)
	{
		fr(j, m)
		{
			if(a[i][j] == '.' and !vis[i][j] and i != n-1 and j != m-1 and i != 0 and j != 0)
			{
				cnt++;
				ll x = dfs(i, j);
				//mp[x] = make_pair(i, j);
				sizes.pb(mp(x, mp(i, j)));
			}
		}
	}
	cout << cnt << "\n";
	sort(sizes.begin(), sizes.end());
	 fr(i, sizes.size())
	 	cout << sizes[i].ff << " ";
	cout << "\n";
	ll ans = 0;
	fr(i, sizes.size()-k)
	{
		ans += sizes[i].ff;
	}
	cout << ans << "\n";
	fill(vis, 0);
	fr(i, sizes.size()-k)
	{
		ll xx = sizes[i].ss.ff;
		ll yy = sizes[i].ss.ss;
		//cout << xx << " " << yy << "\n";
		dfs1(xx, yy);
	}
	fr(i, n)
		cout << a[i] << "\n";

	return 0;
}