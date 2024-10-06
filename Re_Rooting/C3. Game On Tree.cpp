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

vector<vi> tree;
vector<bool> isWinning;
vi numLosingChildren, ans;

void dfs1(int node, int parent) {
    numLosingChildren[node] = 0;
    bool allWinning = true;

    for (int child : tree[node]) {
        if (child == parent) continue;
        dfs1(child, node);
        if (!isWinning[child]) {
            numLosingChildren[node]++;
            allWinning = false;
        }
    }
    isWinning[node] = !allWinning;
}

void reroot(int node, int parent) {
    ans[node] = isWinning[node];
    for (int child : tree[node]) {
        if (child == parent) continue;

        bool parentOriginalState = isWinning[node];
        bool childOriginalState = isWinning[child];
        int parentLosingChildren = numLosingChildren[node];
        int childLosingChildren = numLosingChildren[child];

        if (!isWinning[child]) numLosingChildren[node]--;
        isWinning[node] = numLosingChildren[node] != 0;
        numLosingChildren[child] = isWinning[node] ? childLosingChildren : childLosingChildren + 1;
        isWinning[child] = numLosingChildren[child] > 0;

        reroot(child, node);

        isWinning[node] = parentOriginalState;
        isWinning[child] = childOriginalState;
        numLosingChildren[node] = parentLosingChildren;
        //numLosingChildren[child] = childLosingChildren;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    cin >> n >> t;

    tree.assign(n + 1, vi());
    isWinning.assign(n + 1, false);
    numLosingChildren.assign(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    vi initialPositions(t);
    for (int i = 0; i < t; i++) {
        cin >> initialPositions[i];
    }

    dfs1(1, -1);

    ans.resize(n + 1, 0);
    reroot(1, -1);

    for (int start : initialPositions) {
        cout << (ans[start] ? "Ron" : "Hermione") << endl;
    }

    return 0;
}
