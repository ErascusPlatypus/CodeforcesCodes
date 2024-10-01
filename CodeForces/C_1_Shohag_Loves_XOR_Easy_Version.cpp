#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int x, m;
        cin >> x >> m;

        int cnt = 0;
        for (int i = 1; i <= min(2LL * x, m); i++) {
            if (x != i && ((x % (x ^ i)) == 0 || (i % (x ^ i) == 0))) {
                cnt++;
            }
        }

        cout << cnt << endl;
    }
}