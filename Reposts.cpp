//	Chaitanya Aaditya
//	Birla Institute of Technology, Mesra

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
const ll mx = 1e5 + 5;

vector<ll> adj[mx];

string f(string a)
{
	string b = "";
	for(ll i=0; i<a.size(); i++)
	{
		if(a[i] >= 'a' and a[i] <= 'z')
			b += a[i];
		else 
			b += (char) (a[i]+32);
	}
	return b;
}

ll dfs(ll v)
{
	ll res = 0;
	for(ll vv : adj[v])
	{
		res = max(res, dfs(vv)+1);
	}
	return res;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;
	string s1, s2, s3;
	map<string, ll> mp;
	ll ans = -1, c = 0;
	for(ll i=0; i<n; i++)
	{
		cin >> s1 >> s2 >> s3;
		s1 = f(s1);
		s3 = f(s3);
		// mp[s1] = mp[s3] + 1;
		// ans = max(ans, mp[s1]);
		if(mp.find(s1) == mp.end())
		{
			c++;
			mp[s1] = c;
		}
		if(mp.find(s3) == mp.end())
		{
			c++;
			mp[s3] = c;
		}
		adj[mp[s3]].push_back(mp[s1]);
	}
	string ss = "Polycarp";
	ss = f(ss);
	cout << 1+dfs(mp[ss]) << "\n";

	return 0;
}