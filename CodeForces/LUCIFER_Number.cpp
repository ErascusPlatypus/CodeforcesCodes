#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[12][2][100][100] ;
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 61, 67, 71, 73, 79};
int f(int i, int cross, int sume, int sumo, string& s) {
    if (i == s.size()) {
        int diff = abs(sume - sumo);
        return binary_search(primes.begin(), primes.end(), diff) ? 1 : 0;
    }
    if (dp[i][cross][sume][sumo] != -1) return dp[i][cross][sume][sumo];

    int lim = (cross == 1) ? s[i] - '0' : 9;
    int res = 0;

    for (int d = 0; d <= lim; d++) {
        int even = sume , odd = sumo ;
        if(i&1) odd += d ;
        else even += d ;

        res += f(i+1, (cross & (d == s[i] - '0')), even, odd, s);
    }

    return dp[i][cross][sume][sumo] = res;
}

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b ;
        cin >> a >> b ;

        string left = to_string(a-1) ;
        string right = to_string(b) ;

        memset(dp, -1, sizeof(dp));
        int resr = f(0,1,0,0,right) ;
        memset(dp, -1, sizeof(dp));
        int resl = f(0,1,0,0,left);

        cout << resr - resl << endl ;

    }
    return 0;
}