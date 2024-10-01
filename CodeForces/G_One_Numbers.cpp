// 100000000
// 999999999 = 81


#include <bits/stdc++.h>
using namespace std;
int dp[12][2][82];
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 61, 67, 71, 73, 79};

int f(int i, int cross, int sum, string& s) {
    if (i == s.size()) {
        return binary_search(primes.begin(), primes.end(), sum) ? 1 : 0;
    }

    if (dp[i][cross][sum] != -1) return dp[i][cross][sum];

    int lim = (cross == 1) ? s[i] - '0' : 9;
    int res = 0;
    
    for (int d = 0; d <= lim; d++) {
        res += f(i + 1, (cross && (d == (s[i] - '0'))), sum + d, s);
    }
    return dp[i][cross][sum] = res;
}

int32_t main() {
    int t ;
    cin >> t ;

    while(t--) {
        int l, r ;
        cin >> l >> r ;
        
        string left = to_string(l-1) ;
        string right = to_string(r) ;

        memset(dp, -1, sizeof(dp)) ;
        int resr = f(0, 1, 0, right) ;

        memset(dp, -1, sizeof(dp)); 
        int resl = f(0, 1, 0, left) ;

        cout << resr - resl << endl ;


    }
    return 0;
}