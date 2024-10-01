#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k ;
        cin >> n >> k ;
        vector<int> arr(n) ;

        for(int i = 0 ; i < n ; i++) {
            cin >> arr[i] ;
        }

        sort(arr.begin(), arr.end(), greater<int>());
        int rem = k ; 
        int sum = 0 ;

        for(int i = 0 ; i < n ; i++) {
            if(i % 2 == 0) {
                sum += arr[i] ;
            }
            else {
                int want = min(rem, arr[i-1]-arr[i]) ;
                arr[i] += want ;
                rem -= want ;
                sum -= arr[i] ;
            }
        }

        cout << sum << endl ;
    }
}