#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n ;
        cin >> n ;

        string s ;
        cin >> s ;
        int count = 0 ;
        unordered_map<int, int> mp ;

        for(int i = 0 ; i < n ; i++) {
            char ch = s[i] ;
            int num = ch - 'A' ;

            mp[num]++ ;
        }

        for(int i = 0 ; i < 26 ; i++) {
            if(mp[i] >= i+1) {
                count++ ;
            }
        }
        
        cout << count << endl ;
    }
    return 0;
}