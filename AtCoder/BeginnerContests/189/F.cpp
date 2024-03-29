#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(v) v.rbegin(), v.rend()
const ll INF = 1e18;
//const ll NEGINF = -1 * INF;

ll gcd(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

ll my_pow(ll a, ll n, ll m = INF)
{
    ll res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = (res * a) % m;
            n--;
        }
        a = (a * a) % m;
        n /= 2;
    }
    return res;
}

#define double long double

const int N = 2e5 + 5;

//g(i) = a*x+b;

double a[N];
double b[N];
bool bad[N];

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;

    ll pt;
    for (int i = 0; i < k; i++)
    {
        cin >> pt;
        bad[pt] = true;
    }
    double c = 0;
    double v = 0;
    double sum = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (bad[i])
        {
            a[i] = 1.0;
            b[i] = 0;
        }
        else
        {
            a[i] = (double)c / m;
            b[i] = (double)v / m + 1;
        }
        sum += bad[i] - bad[i + m];
        if (sum == m)
        {
            cout << -1 << endl;
            return;
        }
        c += a[i] - a[i + m];
        v += b[i] - b[i + m];
    }

    cout << fixed << setprecision(10) << b[0] / (1 - a[0]) << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif
    int T = 1;
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}