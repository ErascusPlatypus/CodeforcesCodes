#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[20][2][4];

int f(int i, int cross, int cnt, string& s) {
    if (i == s.size()) return 1;
    if (dp[i][cross][cnt] != -1) return dp[i][cross][cnt];

    int lim = (cross == 1) ? s[i] - '0' : 9;

    int res = 0;
    for (int d = 0; d <= lim; d++) { 
        int up = cnt + (d != 0 ? 1 : 0); 
        if (up <= 3) {
            res += f(i + 1, (cross && (d == (s[i] - '0'))), up, s);
        }
    }

    return dp[i][cross][cnt] = res;
}

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        string right = to_string(r);
        string left = to_string(l - 1);
        memset(dp, -1, sizeof(dp));

        int resr = f(0, 1, 0, right);
        memset(dp, -1, sizeof(dp));
        int resl = f(0, 1, 0, left);

        cout << resr - resl << endl;
    }
    return 0;
}
