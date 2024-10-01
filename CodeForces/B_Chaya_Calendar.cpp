#include <bits/stdc++.h>
using namespace std;
#define int long long

int closestMultiple(int n, int x) {
    return ((n / x) + 1) * x;
}

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n ; 
        cin >> n ;

        vector<int> years(n) ;
        for(int i = 0 ; i < n ; i++) cin >> years[i] ;

        int curr = years[0] ;

        for(int i = 1 ; i < n ; i++) {
            curr = closestMultiple(curr, years[i]) ;
        }

        cout << curr << endl ;
    }
    return 0;
}