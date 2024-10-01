#include <bits/stdc++.h>
using namespace std;
#define int long long

int f(int n, int k, vector<int>& heights, vector<int>& dp) {
    if(n == 0) return 0 ;
    if(dp[n] != -1) return dp[n] ;
    
    int mini = INT_MAX ;
    for(int i = 1 ; i <= k ; i++) {
        int j = INT_MAX ;
        if(n - i >= 0 ) {
            j = f(n-i, k, heights, dp) + abs(heights[n] - heights[n-i]);
        }

        mini = min(mini, j) ;
    }

    return dp[n] = mini ;
}

int32_t main() {
    int n, k ;
    cin >> n >> k ;
    vector<int> dp(n, -1) ;

    vector<int> heights(n) ;
    for(int i = 0 ; i < n ; i++) {
        cin >> heights[i] ;
    }

    cout << f(n-1, k, heights, dp) << endl ;
    
}