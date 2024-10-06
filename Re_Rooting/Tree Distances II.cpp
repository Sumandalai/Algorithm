#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define mi map<int,int>
#define umi unordered_map<int,int>
#define si set<int>
#define ms multiset<int>
#define usi unordered_set<int>
#define lb lower_bound
#define ub upper_bound
template<class T> using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> using max_pq = priority_queue<T>;
vi childCount, res;
void dfs(int u, int p, vi adj[], int n)
{
    childCount[u] = 1;
    for(int v : adj[u])
    {
        if(v != p)
        {
            dfs(v, u, adj, n);
            childCount[u] += childCount[v];
            res[u] += res[v] + childCount[v];
        }
    }
}
void dfs2(int u, int p, vi adj[], int n)
{
    if(p != -1)
    {
        res[u] = res[p] - childCount[u] + n - childCount[u];
    }
    for(int v : adj[u])
    {
        if(v != p)
        {
            dfs2(v, u, adj, n);
        }
    }
}
void if_Solution_Hack_karne_aya_hai_next_sem_fail_hoga()
{
    int n;
    cin >> n;
    vi adj[n + 1];
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    childCount.resize(n + 1, 0);
    res.resize(n + 1, 0);
    dfs(1, -1, adj, n);
    dfs2(1, -1, adj, n);
    for(int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
    
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t=1;
    while(t--)
    {
        if_Solution_Hack_karne_aya_hai_next_sem_fail_hoga();
    }
    return 0;
}