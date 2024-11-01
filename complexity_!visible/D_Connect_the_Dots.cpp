#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define mi map<int, int>
#define umi unordered_map<int, int>
#define si set<int>
#define ms multiset<int>
#define usi unordered_set<int>
#define lb lower_bound
#define ub upper_bound
template <class T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using max_pq = priority_queue<T>;
class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    bool unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return 1;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
void if_Solution_Hack_karne_aya_hai_next_sem_fail_hoga()
{
    int n,m;
    cin>>n>>m;
    DisjointSet ds(n);
    vector<vector<int>> arr (n+1,vector<int>(11,0));
    for(int i=0;i<m;i++)
    {
        int a,d,c;
        cin>>a>>d>>c;
        arr[a][d]=max(arr[a][d],c);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=10;j++)
        {
            int itr=arr[i][j];
            int pos=i;
            while(itr-- && pos+j<=n)
            {
                ds.unionBySize(pos,pos+j);
                arr[pos][j]=0;
                pos+=j;
                itr=max(itr,arr[pos][j]);
            }
        }
    }
    //count number of connected components
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(ds.findUPar(i)==i)
        {
            ans++;
        }
    }
    cout<<ans<<endl;

}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        if_Solution_Hack_karne_aya_hai_next_sem_fail_hoga();
    }
    return 0;
}