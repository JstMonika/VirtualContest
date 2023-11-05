#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T> using vec = vector<T>;
template<typename T> using Prior = priority_queue<T>;
template<typename T> using prior = priority_queue<T, vector<T>, greater<T>>;

#define yccc ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define al(a) a.begin(),a.end()
#define F first
#define S second
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i <= n; i++)
#define eb emplace_back
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define debug(x) cout << " > " << #x << ": " << x << endl;
#define devec(v) cout << " > " << #v << ": "; for (auto i : v) cout << i << ' '; cout << endl;
#define devec2(v) cout << " > " << #v << ":\n"; for (auto i : v) { for (auto k : i) cout << ' ' << k; cout << endl; }

const int INF = 1e9;
const int nINF = -1e9;
const ll llINF = 4*1e18;
const int MOD = 1e9+7;

ll& pmod(ll& a, ll b) { a = (a+b) % MOD; return a; }
ll& pmod(ll& a, ll b, ll c) { a = (a+b) % c; return a; }
ll& mmod(ll& a, ll b) { a = (a-b+MOD) % MOD; return a; }
ll& mmod(ll& a, ll b, ll c) { a = (a-b+c) % c; return a; }
ll& tmod(ll& a, ll b) { a = (a*b) % MOD; return a; }
ll mul(ll a, ll b) { return (a*b) % MOD; }
ll mul(ll a, ll b, ll c) { return (a*b) % c; }
ll mPOW(ll a, ll b) { ll res=1; do { if(b%2) tmod(res,a); tmod(a,a); } while (b>>=1); return res; }
ll nPOW(ll a, ll b) { ll res=1; do { if(b%2) res*=a; a*=a; } while (b>>=1); return res; }
ll mFAC(ll a) { ll res = 1; REP1(i, a) tmod(res, i); return res; }
ll nFAC(ll a) { ll res = 1; REP1(i, a) res*=i; return res; }

template<typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) { cout << a.F << ' ' << a.S; return out; }

int main()
{
    yccc;
    
    int c;
    cin >> c;
    
    while (c--) {
        int n;
        cin >> n;
        
        ll val = 0, diff = 0;
        vec<vec<int>> _list(2);
        
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            
            if (tmp == 1) {
                _list[0].eb(i);
                diff += i;
            }
            
            val -= i * tmp;
        }
        
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            
            if (tmp == 2) {
                _list[1].eb(i);
                diff += i;
            }
            
            val += i * tmp;
        }
        
        if (val < 0)
            cout << -1 << endl;
        else if (val == 0)
            cout << 0 << endl;
        else if (diff < val)
            cout << -1 << endl;
        else {
            vector<bitset<100>> num(val+1);
            
            for (int z = 0; z < 2; z++) {
                vec<vec<bitset<100>>> dp(_list[z].size(), vec<bitset<100>>(val+1));

                for (int i = 0; i < _list[z].size(); i++)
                    for (int k = 1; k <= val; k++)
                    {
                        if (i) {
                            dp[i][k] = dp[i-1][k];
                            
                            if (_list[z][i] < k)
                                dp[i][k] |= (dp[i-1][k - _list[z][i]] << 1);
                        }

                        if (_list[z][i] == k) {
                            bitset<100> b(1);
                            dp[i][k] |= b;
                        }
                    }
                    
                if (z) {
                    int ans = 200;
                    
                    for (int i = 1; i < val; i++)
                        for (int k = 0; k < 100; k++)
                            if (dp[_list[z].size() - 1][i][k] && num[val-i][k])
                                ans = min(ans, k+1);
                   
                    cout << (ans == 200 ? -1 : ans) << endl;
                }
                else {
                    for (int i = 1; i <= val; i++)
                        num[i] = dp[_list[z].size() - 1][i];
                }
            }
        }
    }
}