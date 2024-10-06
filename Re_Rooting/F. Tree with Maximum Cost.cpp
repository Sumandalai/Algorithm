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
vector<vi> adj;
vector<int> a;
vector<int> sum;
vector<int> cost;
int total_sum = 0;
int ans = 0;
 
void preCal(int u , int prev)
{
    sum[u] = a[u];
    for (auto v : adj[u])
    {
        if (v == prev) continue;
        preCal(v, u);
        sum[u] += sum[v];
        cost[u] += sum[v] + cost[v];
    }
}
 
void dfs(int u, int prev)
{
    ans = max(ans, cost[u]);
    for (auto v : adj[u])
    {
        if (v == prev) continue;
        int newCost = cost[u] - cost[v] - sum[v];
        cost[v] += newCost + total_sum - sum[v];
       
        dfs(v, u);
    }
}
void if_Solution_Hack_karne_aya_hai_next_sem_fail_hoga()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    a.resize(n + 1);
    sum.resize(n + 1, 0);
    cost.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    preCal(1, 0);
    total_sum = sum[1];
    dfs(1, 0);
    cout << ans << endl;
    
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