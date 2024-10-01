#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n ;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        vector<int> arr(n) ;
        for (int i = 0; i < n; i++) cin >> arr[i];

        int min1 = *min_element(nums.begin() , nums.end()) ;
        int sum1 = accumulate(arr.begin() , arr.end() , 0LL) ;
        
        int min2 = *min_element(arr.begin() , arr.end()) ;
        int sum2 = accumulate(nums.begin() , nums.end() , 0LL) ;


        int sum = min(sum1 + min1*n , sum2 + min2*n) ;
        

        cout << sum << endl ;
    }
    return 0;
}