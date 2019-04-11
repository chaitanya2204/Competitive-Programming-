//	Chaitanya Aaditya
//	Birla Institute of Technology, Mesra
//	https://codeforces.com/problemset/problem/279/C

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

ll a[mx], l[mx], r[mx];

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
	fr1(i, n)	cin >> a[i];
	ll j = 1;
	fr1(i, n)
	{
		if(a[i] > a[i-1])
			j = i;
		l[i] = j;
	}
	j = n;
	for(ll i=n; i>=1; i--)
	{
		if(a[i+1] < a[i])
			j = i;
		r[i] = j;
	}
	while(m--)
	{
		ll x, y;
		cin >> x >> y;
		if(r[x] >= l[y])
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}