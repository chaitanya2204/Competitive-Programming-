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
const ll mod = 1e9 + 7;
const ll mx = 3e5 + 5;

ll ncr[5005][5005];
ll fn(ll n, ll r)
{
	if(ncr[n][r] != 0)
		return ncr[n][r];
	if(n == r)
		return 1;
	if(r == 0)
		return 1;
	if(r == 1)
		return n;
	return ncr[n][r] = fn(n-1, r) + fn(n-1, r-1);
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	ll n;
	cin >> n;
	string s1;
	map<char,ll> mp, mp1;
	set<char> st;
	fill(ncr, 0);
	for(ll i=0; i<n; i++)
	{
		char c;
		cin >> c;
		s1 += c;
		st.insert(c);
		mp1[c]++;
	}
	fr(i, s.size())
	{
		mp[s[i]]++;
	}
	set<char>:: iterator itr;
	ll ans = 1;
	for(itr=st.begin(); itr!=st.end(); itr++)
	{
		//cout << *itr << " " << mp[*itr] << " " << mp1[*itr] << "\n";
		if(mp1[*itr] > mp[*itr])
		{
			cout << "0\n";
			return 0;
		}
		if(mp[*itr] == mp1[*itr])
			continue;
		ans *= fn(mp[*itr], mp1[*itr]);
		ans %= mod;
	}
	cout << ans << "\n";


	return 0;
}