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
void if_Solution_Hack_karne_aya_hai_next_sem_fail_hoga()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
 
    vector<int> vec;
    int x = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1')
            x++;
        else
            x--;
        if (i > 0)
            vec.push_back(x);
    } 
    int sum = 0;
    sort(vec.rbegin(), vec.rend()); 
    int ans = 1;
    for (auto i : vec) {
        sum += i;
        ans++;
        if (sum >= k) {
            cout << ans << '\n';
            return;
        }
    }
    cout << "-1\n";
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