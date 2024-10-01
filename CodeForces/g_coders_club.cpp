#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll l, r, k;
    cin >> l >> r >> k;

    auto check = [&](ll x) {
        ll cnt = (r / x) - ((l - 1) / x);
        return cnt >= k;
    };

    ll left = l, right = r, best = l - 1;
    while (left <= right) {
        ll mid = (left + right) >> 1;
        if (check(mid)) {
            best = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    ll ans = max(0LL, best - l + 1);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}