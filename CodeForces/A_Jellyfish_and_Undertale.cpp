#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int a , b, n , sum = 0 ;
        cin >> a >> b >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        sum = b ;
        for(int i = 0 ; i < n ; i++) {
            sum += min(nums[i] , a-1) ;
        }

        cout << sum << endl ;
    }
    return 0;
}