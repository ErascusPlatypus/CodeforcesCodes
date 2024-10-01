#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k ;
        cin >> n >> k ;

        vector<int> cards(n) ;
        unordered_map<int, int> mp ;
        int ans = n ; 

        for(int i = 0 ; i < n ; i++) {
            cin >> cards[i];
            mp[cards[i]]++ ;

            if(mp[cards[i]]>=k) {
                ans = k - 1 ;
            }
        }

        cout << ans << endl ;

    }
    return 0;
}