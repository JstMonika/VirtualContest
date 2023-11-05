#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<typename T> using vec = vector<T>;
template<typename T> using deq = deque<T>;
template<typename T> using p = pair<T, T>;

#define yccc ios_base::sync_with_stdio(false), cin.tie(0)
#define endl '\n'
#define al(a) a.begin(),a.end()
#define F first
#define S second
#define eb emplace_back

int main() {
    yccc;
    
    int n;
    cin >> n;
    
    string str;
    cin >> str;
    
    int left = 1, lc = 1, right = (1<<n), rc = -1;
    for (int i = 0; i < n; i++) {
        if (str[i] == '1') {
            left += lc;
            lc *= 2;
        } else {
            right += rc;
            rc *= 2;
        }
    }
    
    for (int i = left; i <= right; i++) {
        cout << i << " \n"[i == right];
    }
}