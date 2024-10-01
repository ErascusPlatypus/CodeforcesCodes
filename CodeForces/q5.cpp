#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    ll total_sum = 0;
    while(q--) {
        int start, jump;
        cin >> start >> jump;
        
        ll sum = 0;
        for(int i = start; i < n; i += jump) {
            sum = (sum + a[i]) % MOD;
        }
        total_sum = (total_sum + sum) % MOD;
    }
    
    cout << total_sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}