#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n , k , diff ;
        cin >> n >> k ;

        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            if(nums[i] == k) {
                cout << 0 << endl ;
                continue; 
            }
        }

        set<int> mp ;

        for(int i = 0 ; i < n ; i++) {
            diff = k - nums[i] ;
            if(diff > 0) {
                mp.insert(diff) ;
            }
        }

        cout << *mp.begin() << endl ;

        


    }
    return 0;
}