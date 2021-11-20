#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define deb(x) cout << #x << " " << x << endl;
#define EACH(x, a) for (auto &x : a)
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

template <typename... T>
void read(T &...args)
{
    ((cin >> args), ...);
}

template <class A>
void read(vector<A> &x)
{
    EACH(a, x)
    read(a);
}

template <typename... T>
void print(T &&...args)
{
    ((cout << args << " "), ...);
}

template <class A>
void print(vector<A> &x)
{
    EACH(a, x)
    print(a);
    cout << endl;
}

template <typename... T>
void println(T &&...args)
{
    ((cout << args << " "), ...);
    cout << endl;
}

void solve()
{
    int n, m;
    read(n, m);
    string s;
    cin >> s;
    if (n == 1 && m == 1)
    {
        println("1 1");
        return;
    }
    int sz = s.size();
    vector<pair<int, int>> lst(sz + 1);
    lst[0] = {0, 0};
    for (int i = 0; i < sz; i++)
    {
        lst[i + 1] = lst[i];
        if (s[i] == 'R')
        {
            lst[i + 1].second++;
        }
        else if (s[i] == 'L')
        {
            lst[i + 1].second--;
        }
        else if (s[i] == 'U')
        {
            lst[i + 1].first--;
        }
        else
        {
            lst[i + 1].first++;
        }
        // cout << lst[i + 1].first << " " << lst[i + 1].second << "\n";
    }
    for (int i = sz; i >= 1; i--)
    {
        int x = lst[i].first;
        int y = lst[i].second;
        if (x <= 0 && y <= 0 && x >= -n + 1 && y >= -m + 1)
        {
            cout << "1 " << m << endl;
            return;
        }
        if (x >= 0 && y >= 0 && x <= n - 1 && y <= m - 1)
        {
            cout << n << " 0" << endl;
            return;
        }
        if (x <= 0 && y >= 0 && x >= -n + 1 && y <= m - 1)
        {
            cout << n << " " << m << endl;
            return;
        }
        if (x >= 0 && y <= 0 && x <= n - 1 && y >= -m + 1)
        {
            cout << "1 1" << endl;
            return;
        }
        if (x == 0 && y == 0)
        {
            cout << "1 1" << endl;
            return;
        }
    }
}

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main()
{
    file_i_o();
    int t = 1;
    read(t);
    while (t--)
    {
        solve();
    }
    return 0;
}
