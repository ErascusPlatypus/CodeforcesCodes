#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i].first;
        nums[i].second = i + 1;  
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        int rem = x - nums[i].first;
        int l = i + 1;
        int r = n - 1;

        while (l < r) {
            int sum = nums[l].first + nums[r].first;
            if (sum == rem) {
                cout << nums[i].second << " " << nums[l].second << " " << nums[r].second << endl;
                return 0;
            } else if (sum < rem) {
                l++;
            } else {
                r--;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
