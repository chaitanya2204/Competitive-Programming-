//  Chaitanya Aaditya
//  Birla Institute of Technology, Mesra

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

ll n, ans = 0;
vector<ll> adj[mx], root;
vector<pair<ll,ll> > back;
map<pair<ll,ll>, ll> m;
bool vis[mx];

void dfs(ll s, ll p)
{
    vis[s] = 1;
    fr(i, adj[s].size())
    {
        ll curr = adj[s][i];
        if(curr == p)
            continue;
        if(!vis[curr])
            dfs(curr, s);
        else
            back.pb(mp(s, curr));
    }
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
    fr(i, n)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    fr1(i, n)
    {
        if(!vis[i])
        {
            dfs(i, 0);
            ans++;
            root.pb(i);
        }
    }
    cout << ans - 1 << "\n";
    ll j = 0;
    fr(i, root.size()-1)
    {
        if(!m[mp(back[j].ff, back[j].ss)])
        {
            m[mp(back[j].ff, back[j].ss)] = 1;
            m[mp(back[j].ss, back[j].ff)] = 1;
            cout << back[j].ff << " " << back[j].ss << " " << root[i] << " " << root[i+1] << "\n";
        }
        j++;
    }

    return 0;
}