#include <bits/stdc++.h>
using namespace std;

pair<int, int> findLongestSegment(int s, const vector<int>& transactions) {
    int n = transactions.size();
    int start = 0, currentStart = 0;
    int maxLength = 0, currentLength = 0;
    int balance = s;

    for (int i = 0; i < n; i++) {
        balance += transactions[i];

        if (balance >= 0) {
            currentLength++;
            if (currentLength > maxLength) {
                maxLength = currentLength;
                start = currentStart;
            }
        } else {
            // Reset the window
            balance = s;
            currentStart = i + 1;
            currentLength = 0;
        }
    }

    if (maxLength == 0) {
        return {0, 0}; // No valid segment
    }

    return {start + 1, start + maxLength}; // 1-based indexing
}

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n, s ;
        cin >> n >> s ;

        vector<int> nums(n);
        for(int i = 0 ; i < n ; i++) {
            cin >> nums[i] ;
        }

        // int l = 0, r = 0 ;
        // int curr = 0, sz = 0, p = 0 ; 

        // while(r < n) {
        //     curr += nums[r] ;

        //     while(curr < 0 && l <= r) {
        //         curr -= nums[l] ;
        //         l++ ; 
        //     }

        //     if(sz < r-l+1) {
        //         sz = r-l+1 ;
        //         p = r+1 ;
        //     }
        //     r++ ;
        // }

        pair<int, int> result = findLongestSegment(s, nums);
        if(result.first == 0 && result.second == 0) cout << -1 << endl ;
        else cout << result.first << " " << result.second << endl;

    }
    return 0;
}