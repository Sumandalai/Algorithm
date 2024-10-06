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
vi dp;
void dfs1(int u, int p, vector<pii> adj[]){
  for(auto& edge : adj[u]){
    int v = edge.first;
    int w = edge.second;
    if(v == p) continue;
    dfs1(v, u, adj);
    dp[u] +=(dp[v] + w);
  }
}
void dfs2(int u, int p, vector<pii> adj[]){
    for(auto& edge : adj[u]){
        int v = edge.first;
        int w = edge.second;
        if(v == p) continue;
        dp[v] = dp[u] +(w ? -1 : 1);
        dfs2(v, u, adj);
    }
  
}
void if_Solution_Hack_karne_aya_hai_next_sem_fail_hoga()
{
    int n;
    cin >> n;
    vector<pii> adj[n + 1];
    dp.resize(n + 1, 0);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
         cin >> u >> v;
        adj[u].pb({v, 0});
        adj[v].pb({u, 1});
    }
    dfs1(1, 0, adj);
    dfs2(1, 0, adj);
    vi ans;
    for(int i = 1; i <= n; i++)
    {
        if(ans.empty() || dp[i] < dp[ans[0]])
        {
            ans.clear();
            ans.pb(i);
        }
        else if(dp[i] == dp[ans[0]])
        {
            ans.pb(i);
        }
    }
    cout << dp[ans[0]] << endl;
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    while(t--)
    {
        if_Solution_Hack_karne_aya_hai_next_sem_fail_hoga();
    }
    return 0;
}