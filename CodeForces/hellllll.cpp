#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto count_zero_subarrays = [&](const vector<int>& arr) {
        ll result = 0;
        int last_zero = -1;
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0) {
                result += (ll)(i - last_zero) * (n - i);
                last_zero = i;
            }
        }
        return result;
    };

    ll original_count = count_zero_subarrays(a);
    
    ll max_count = original_count;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) {
            a[i] = 0;
            max_count = max(max_count, count_zero_subarrays(a));
            a[i] = 1;
        }
    }

    cout << max_count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}