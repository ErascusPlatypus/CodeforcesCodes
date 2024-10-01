#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[12][2][2] ; 

int f(int i, int cross, int flag, string& s) {
    if(i == s.size()) return flag; 

    if(dp[i][cross][flag] != -1) return dp[i][cross][flag] ;

    int lim = (cross == 1) ? s[i] - '0' : 9 ; 
    int res = 0 ; 

    for(int d = 0 ; d <= lim ; d++) {
        int up = (flag | (d == 3)) ;
        res += f(i+1, (cross && (d == (s[i] - '0'))), up, s) ; 
    }

    return dp[i][cross][flag] = res ;
}   

int32_t main() {
    int t ; 
    cin >> t ;

    while(t--) {
        int n ; 
        cin >> n ; 

        string s = to_string(n) ;
        memset(dp, -1, sizeof(dp)) ;
        int sub = f(0, 1, 0, s) ;

        cout << n - sub << endl ;

    }
    return 0;
}