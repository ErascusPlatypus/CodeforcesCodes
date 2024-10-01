#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n ;
        cin >> n ;

        vector<int> nums(2*n) ;

        for(int i = 0 ; i < 2*n ; i++) {
            cin >> nums[i] ;
        }

        sort(nums.begin(), nums.end(), greater<int>()) ;
        int sum = 0 ;

        for(int i = 1 ; i < 2*n ; i+=2) {
            sum += nums[i] ;
        }

        cout << sum << endl ;
    }
    return 0;
}