#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        int count = 0, c = 0, k = 0;

        while(count < n && nums[count] == nums[0]) {
            count++ ;
        }
        while(c < n && nums[n - c - 1] == nums[n-1]) {
            c++ ;
        }        

        if (nums[0] == nums[n - 1])
            k = count + c;
        else
            k = max(count, c);

        int maxi = n - k;
        cout << max(maxi, 0LL) << endl;
    }
    return 0;
}
