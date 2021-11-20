#include <bits/stdc++.h>
using namespace std;
#define FOR(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define deb(x) cout << #x << " " << x << endl;
#define EACH(x, a) for (auto& x: a)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int s);
void bfs(int x);

template <typename... T> void read(T &... args)
{
    ((cin >> args), ...);
}

template<class A> void read(vector<A>& x)
{
    EACH(a, x)
        read(a);
}

template <typename... T>
void print(T &&... args)
{
    ((cout << args << " "), ...);
}

template<class A> void print(vector<A>& x)
{
    EACH(a, x)
        print(a);
    cout << endl;
}

const int mod = 1'000'000'007;
const int N = 3e5, M = N;

vi g[N];
queue<int> q;
bool visited[N];
int dist[N];

void solve()
{
    int i, j, n, m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t = 1, i = 1;
    read(t);
    while (t--)
    {
        // cout << "Case #" << i << ": ";
        // solve();
        // ++i;

        solve();
    }
    return 0;
}

int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void ipgraph(int n, int m)
{
    int i, u, v;
    while (m--)
    {
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
}

void dfs(int s)
{
    if (visited[s])
        return;
    visited[s] = true;
    // process node s
    for (auto u : g[s])
    {
        dfs(u);
    }
}

void bfs(int x)
{
    visited[x] = true;
    dist[x] = 0;
    q.push(x);
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        // process node s
        for (auto u : g[s])
        {
            if (visited[u])
                continue;
            visited[u] = true;
            dist[u] = dist[s] + 1;
            q.push(u);
        }
    }
}
