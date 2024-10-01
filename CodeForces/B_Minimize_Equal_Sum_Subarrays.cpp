#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n ;
        cin >> n ;

        vector<int> vec(n) ;

        for(int i = 0 ; i < n ; i++) {
            cin >> vec[i];
        }

        reverse(vec.begin(), vec.end()) ;

        for(int i = 1 ; i < n ; i++) {
            cout << vec[i] << " " ;
        }
        cout << vec[0] ;

        cout << endl ;
    }
    return 0;
}