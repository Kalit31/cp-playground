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
const ll N = 1e6 + 1;

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

void solve()
{
    ll n;
    cin >> n;
    vector<array<ll, 2>> pts(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pts[i][0] >> pts[i][1];
    }
    ll m;
    cin >> m;
    vector<array<ll, 3>> x(m + 1);
    vector<array<ll, 3>> y(m + 1);
    x[0] = {1, 0, 0};
    y[0] = {0, 1, 0};
    ll op1, op2;
    for (int i = 0; i < m; i++)
    {
        cin >> op1;
        if (op1 == 1)
        {
            x[i + 1] = y[i];
            y[i + 1] = {-x[i][0], -x[i][1], -x[i][2]};
        }
        else if (op1 == 2)
        {
            x[i + 1] = {-y[i][0], -y[i][1], -y[i][2]};
            y[i + 1] = x[i];
        }
        else if (op1 == 3)
        {
            cin >> op2;
            x[i + 1] = {-x[i][0], -x[i][1], -x[i][2] + 2 * op2};
            y[i + 1] = y[i];
        }
        else
        {
            cin >> op2;
            x[i + 1] = x[i];
            y[i + 1] = {-y[i][0], -y[i][1], -y[i][2] + 2 * op2};
        }
    }

    ll q;
    cin >> q;
    int a, b;
    while (q--)
    {
        cin >> a >> b;
        b--;
        ll currX = pts[b][0] * x[a][0] + pts[b][1] * x[a][1] + x[a][2];
        ll currY = pts[b][0] * y[a][0] + pts[b][1] * y[a][1] + y[a][2];
        cout << currX << " " << currY << endl;
    }
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