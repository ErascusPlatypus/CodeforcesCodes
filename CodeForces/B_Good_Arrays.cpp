#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n , f = 0 ;
        cin >> n;

        unordered_map<int,int> mp ;

        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            mp[nums[i]]++ ;
        }

        for(auto& m : mp) {
            if(m.second > floor(n/2)) {
                f = 1; 
                continue;
            }
        }

        if(f==1) cout << "NO" << endl ;
        else cout << "YES" << endl ;
    }
    return 0;
}