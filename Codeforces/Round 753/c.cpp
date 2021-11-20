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
    ll start, n;
    cin >> start >> n;
    n++;
    if (start & 1)
    {
        if (n % 4 == 1)
        {
            start -= (n / 4) * 4;
            start += (n - 1);
        }
        else if (n % 4 == 2)
        {
            start -= (n / 4) * 4;
            start += (n - 1 + n - 2);
        }
        else if (n % 4 == 3)
        {
            start -= 1;
        }
        else
        {
            start -= (n / 4) * 4;
        }
    }
    else
    {
        if (n % 4 == 1)
        {
            start += (n / 4) * 4;
            start -= (n - 1);
        }
        else if (n % 4 == 2)
        {
            start += (n / 4) * 4;
            start -= (n - 1 + n - 2);
        }
        else if (n % 4 == 3)
        {
            start += 1;
        }
        else
        {
            start += (n / 4) * 4;
        }
    }
    cout << start << "\n";
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
