//	Chaitanya Aaditya
//	Birla Institute of Technology, Mesra
//	https://codeforces.com/problemset/problem/1114/D

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
const ll mx = 5005;

ll n, a[mx], dp[mx][mx];

ll fn(ll i, ll j)
{
	if(dp[i][j] != -1)
		return dp[i][j];
	if(i >= j)
		return 0;
	dp[i][j] = min(fn(i+1, j) + (a[i] != a[j]), fn(i, j-1) + (a[j] != a[j-1]));
	if(a[i] == a[j])
		dp[i][j] = min(dp[i][j], 1 + fn(i+1, j-1));
	return dp[i][j];
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	fr(i, n)	cin >> a[i];
	fill(dp, -1);
	cout << fn(0, n-1) << "\n";

	return 0;
}