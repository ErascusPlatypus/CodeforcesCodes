#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int f(int i, int prev, vector<int> &arr, int n) {
    if (i == n) return 1;

    if (dp[i][prev+1] != -1) return dp[i][prev+1];

    int res = 0;
    for (int d = 0; d < arr.size(); d++) {
        if ((prev == -1) || (abs(arr[d] - arr[prev]) <= 2)) {
            res += f(i + 1, d, arr, n);
        }
    }

    return dp[i][prev+1] = res;
}

int32_t main() {
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++) {
        int m, n;
        cin >> m >> n;

        vector<int> arr(m);
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
        }

        dp.assign(n, vector<int>(m + 1, -1)); 
        int res = f(0, -1, arr, n);

        cout << "Case " << z << ": " << res << endl;
    }

    return 0;
}
