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
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        string str;
        cin >> str;
        
        bool now = (str[0] == '1');
        for (int i = 1; i < n; i++) {
            if (str[i] == '1') {
                cout << (now ? '-' : '+');
                now = !now;
            } else {
                cout << '+';
            }
        }
        
        cout << endl;
    }
}