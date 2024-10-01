#include <bits/stdc++.h>
using namespace std;

int getLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Get original LIS
    int maxLIS = getLIS(a);
    
    // Try all possible reversals
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            // Reverse subarray [i,j]
            reverse(a.begin() + i, a.begin() + j + 1);
            maxLIS = max(maxLIS, getLIS(a));
            // Restore array
            reverse(a.begin() + i, a.begin() + j + 1);
        }
    }
    
    cout << maxLIS << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}