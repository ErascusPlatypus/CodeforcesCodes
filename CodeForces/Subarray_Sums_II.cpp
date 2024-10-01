#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n, k ;
    cin >> n >> k ; 

    vector<int> nums(n) ;
    for(int i = 0 ; i < n ; i++) {
        cin >> nums[i] ;
    }

    unordered_map<int, int> mp ;
    mp[0] = 1 ; 
    int curr = 0, cnt = 0 ;   
    for(int i = 0 ; i < n ; i++) {
        curr += nums[i] ;   

        if(mp.find(curr - k) != mp.end()) {
            cnt += mp[curr-k] ;
        }

        mp[curr]++ ;
    }

    cout << cnt << endl ;




    return 0;
}