#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n , k , x ;
        cin >> n >> k >> x ;

        vector<int> arr(n) ;
        for(int i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end(), greater<int>());

        
    }
    return 0;
}