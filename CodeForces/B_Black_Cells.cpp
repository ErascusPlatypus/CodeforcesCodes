#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        
        vector<ll> gaps;
        for (int i = 1; i < n; ++i) {
            gaps.push_back(a[i] - a[i-1]);
        }
        
        if (n % 2 == 0) {
            ll max_gap = *max_element(gaps.begin(), gaps.end());
            cout << max_gap << '\n';
        } else {
            ll max_gap = *max_element(gaps.begin(), gaps.end());
            bool skipped = false;
            ll second_max = 0;
            for (ll g : gaps) {
                if (g == max_gap && !skipped) {
                    skipped = true;
                    continue;
                }
                if (g > second_max) {
                    second_max = g;
                }
            }
            ll split_max = (max_gap + 1) / 2;
            ll ans = max(second_max, split_max);
            cout << ans << '\n';
        }
    }
    
    return 0;
}