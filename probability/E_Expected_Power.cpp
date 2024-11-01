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
const int MOD = 1e9 + 7;
const int N = 2e5 + 1, M = 1024;


vector<int> a, b, take, notTake;

int expo(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (1ll * res * a) % MOD;
        b >>= 1;
        a = (1ll * a * a) % MOD;
    }
    return res;
}

void if_Solution_Hack_karne_aya_hai_next_sem_fail_hoga()
{
    int n;
    cin >> n;
    a.resize(n, 0), b.resize(n, 0), take.resize(n, 0), notTake.resize(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int modInv = expo(1e4, MOD - 2);
    for (int i = 0; i < n; i++)
    {
        take[i] = (1ll * b[i] * modInv) % MOD;
        notTake[i] = (1 - take[i] + MOD) % MOD;
    }
    vector<int> dp(M, 0);
    vector<int>ndp(M,0);
    for (int index =n; index >= 0; index--)
    {
        for (int curXor = 0; curXor < M; curXor++)
        {
            if (index == n)
            {
                dp[curXor]= (curXor == 0);
                continue;
            }
            dp[curXor] = (1ll * notTake[index] * ndp[curXor]) % MOD;
            dp[curXor] = (dp[curXor] + 1ll * take[index] * ndp[curXor ^ a[index]]) % MOD;
        }
        ndp=dp;
    }

      int sum = 0;
 
        for (int i = 0; i < M; i++) {
            sum = (1ll * sum + 1ll * i * i * dp[i]) % MOD;
        }
     cout << sum <<endl;
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