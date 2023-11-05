#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<typename T> using p = pair<T, T>;
template<typename T> using vec = vector<T>;
template<typename T> using deq = deque<T>;

#define dbg

#define yccc ios_base::sync_with_stdio(false), cin.tie(0)
#define al(a) a.begin(),a.end()
#define F first
#define S second
#define eb emplace_back

#ifndef dbg
#define endl '\n'
#define debug(x) ;
#define devec(v) ;
#define devec2(v) ;
#else
#define debug(x) cout << " > " << #x << ": " << x << endl;
#define devec(v) cout << " > " << #v << ": "; for (auto i : v) cout << i << ' '; cout << endl;
#define devec2(v) cout << " > " << #v << ":\n"; for (auto i : v) { for (auto k : i) cout << ' ' << k; cout << endl; }
#endif

const int INF = 1e9;
const ll llINF = 1e18;
const int MOD = 998244353;
const double eps = 1e-6;
const double PI = acos(-1);

double fcmp(double a, double b, double eps = 1e-6) {
    if (fabs(a-b) < eps) return 0;
    return a - b;
}

template<typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) { in >> a.F >> a.S; return in; }

template<typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) { out << a.F << ' ' << a.S; return out; }

const int MAX = 2000005;

ll fact[MAX], tcaf[MAX]

// Call this first.;
void init(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = i * fact[i - 1] % MOD;
    for (int i = n; i >= 0; --i)
        tcaf[i] = deg(fact[i], -1);
}
ll deg(ll x, ll d) {
    if (d < 0) d += MOD - 1;
    ll y = 1;
    while (d) {
        if (d & 1) (y *= x) %= MOD;
        d /= 2;
        (x *= x) %= MOD;
    }
    return y;
}

// Invoke nCr via this.
ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * tcaf[r] % MOD * tcaf[n - r] % MOD;
}

ll nHr(int n, int r) {
    if (r == 0) return 1;
    
    return nCr(n+r-1, r);
}

int main()
{
    yccc;
    
    init(2000000);
    
    ll r, g, b, k;
    cin >> r >> g >> b >> k;
    
    // debug(r);
    // debug(g);
    // debug(b);
    // debug(k);
    // cout << b+1 << ' ' << g-r << endl;
    // cout << nHr(k+1, b) << ' ' << nHr(k+b+1, g-k) << ' ' << nHr(b+k+1, r-k) << endl;
    cout << ((nHr(k+1, b) * nHr(k+b+1, g-k) % MOD) * nHr(b+k+1, r-k) % MOD);
}