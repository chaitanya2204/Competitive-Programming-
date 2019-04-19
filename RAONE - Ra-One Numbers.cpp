#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7;

ll dp[15][105][105][2];

ll fn(string &s, ll idx, ll sumEven, ll sumOdd, bool f)
{
	if(dp[idx][sumEven][sumOdd][f] != -1)
		return dp[idx][sumEven][sumOdd][f];
	if(idx == s.size())
	{
		if(sumEven - sumOdd == 1)
			return 1;
		return 0;
	}
	ll res = 0;
	if(f)
	{
		for(ll i=0; i<=s[idx]-'0'; i++)
		{
			if(i == s[idx]-'0')
				res += fn(s, idx+1, sumOdd, sumEven+i, 1);
			else
				res += fn(s, idx+1, sumOdd, sumEven+i, 0);
		}
	}
	else
	{
		for(ll i=0; i<=9; i++)
		{
			res += fn(s, idx+1, sumOdd, sumEven+i, 0);
		}
	}
	return dp[idx][sumEven][sumOdd][f] = res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin >> t;
	while(t--)
	{
		ll a, b;
		cin >> a >> b;
		a--;
		string aa, bb;
		aa = to_string(a);
		bb = to_string(b);
		//cout << aa << " " << bb << "\n";
		memset(dp, -1, sizeof dp);
		ll ansR = fn(bb, 0, 0, 0, 1);
		memset(dp, -1, sizeof dp);
		ll ansL = fn(aa, 0, 0, 0, 1);
		cout << ansR - ansL << "\n";

	}

	return 0;
}