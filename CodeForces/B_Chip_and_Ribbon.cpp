#include <bits/stdc++.h>
using namespace std;
#define int long long 

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n ; 
        cin >> n ;

        vector<int> vec(n) ;
        for(int i = 0 ; i < n ; i++) {
            cin >> vec[i] ;
        }

        int ans = vec[0]-1 ;
        int curr = vec[0] ;

        for(int i = 1 ; i < n ; i++) {
            if(curr < vec[i]) {
                ans += vec[i]-curr ;
            }

            curr = vec[i] ;
        }

        cout << ans << endl ;
    }
    return 0;
}