#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n , k , count = 0 ;
        cin >> n >> k ;

        string s ;
        cin >> s ;

        map<char , int> mp ;

        for(int i = 0 ; i < n ; i++) {
            mp[s[i]]++ ;
        }

        for(auto& m : mp) {
            if(m.second % 2 == 1) count++ ;
        }

        if(count > k+1) cout << "NO" << endl ;
        else cout << "YES" << endl ;
    }
    return 0;
}