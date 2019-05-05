//	Chaitanya Aaditya
//	Birla Institute of Technology, Mesra
//	https://codeforces.com/contest/296/problem/C

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
ll l[mx], r[mx], d[mx];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m, k;
	cin >> n >> m >> k;
	ll a[n+1];
	fr1(i, n)	cin >> a[i];
	fr1(i, m)	cin >> l[i] >> r[i] >> d[i];
	ll cnt[mx];
	fr1(i, k)	
	{
		ll x, y;
		cin >> x >> y;
		cnt[x]++;
		cnt[y+1]--;
	}
	fr1(i, m)	cnt[i] += cnt[i-1], d[i] *= cnt[i];
	fill(cnt, 0);
	fr1(i, m)
	{
		cnt[l[i]] += d[i];
		cnt[r[i]+1] -= d[i];
	}
	fr1(i, n)
	{
		cnt[i] += cnt[i-1];
		cout << cnt[i] + a[i] << " ";
	}
	cout << "\n";

	return 0;
}