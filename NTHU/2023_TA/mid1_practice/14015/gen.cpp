#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<typename T> using p = pair<T, T>;
template<typename T> using vec = vector<T>;
template<typename T> using deq = deque<T>;

#define yccc ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define al(a) a.begin(),a.end()
#define F first
#define S second
#define eb emplace_back

mt19937 ran(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    yccc;

	int n = ran() % 10000 + 1, r = ran() % 9 + 2;

	cout << n << ' ' << r << endl;
}
