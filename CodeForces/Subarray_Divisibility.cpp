#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n ;
    cin >> n ;

    vector<int> nums(n) ;
    for(int i = 0 ; i < n ; i++) {
        cin >> nums[i] ;
    }

    unordered_map<int, int> mp ;
    mp[0] = 1 ;

    int curr = 0, res = 0 ; 
    for(int i = 0 ; i < n ; i++) {
        curr += nums[i] ;

        int mod = ((curr % n) + n) % n ; 

        res += mp[mod] ; 

        mp[mod]++ ;
    }

    cout << res << endl ;
    return 0;
}