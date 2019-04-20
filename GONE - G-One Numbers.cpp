#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;

ll dp[15][105][2];
ll fuck[105];
string s;

void seive()
{
	for(ll i=2; i*i<=100; i++)
	{
		if(!fuck[i])
		{
			for(ll j=i*2; j<=100; j+=i)
			{
				fuck[j] = 1;
			}
		}
	}
	for(ll i=2; i<=100; i++)
	{
		if(!fuck[i])
			fuck[i] = -1;
	}
}

ll fn(ll idx, ll sum, bool f)
{
	if(dp[idx][sum][f] != -1)
		return dp[idx][sum][f];
	if(idx == s.size())
		return fuck[sum] == -1;
	ll res = 0;
	for(ll i=0; i<10; i++)
	{
		if(f or i <= (s[idx]-'0'))
		{
			res += fn(idx+1, sum+i, f or i < (s[idx]-'0'));
		}
	}
	return dp[idx][sum][f] = res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(fuck, 0, sizeof fuck);
	ll t;
	cin >> t;
	seive();
	while(t--)
	{
		ll a, b;
		cin >> a >> b;
		a--;
		s = to_string(b);
		memset(dp, -1, sizeof dp);
		ll ansR = fn(0, 0, 0);
		s = to_string(a);
		memset(dp, -1, sizeof dp);
		ll ansL = fn(0, 0, 0);
		cout << ansR - ansL << "\n";
	}

	return 0;
}