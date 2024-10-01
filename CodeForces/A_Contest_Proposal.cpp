#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n , c = 0 ;
        cin >> n ;

        vector<int> a(n) ;
        vector<int> b(n) ;

        for(int i = 0 ; i < n ; i++) cin >> a[i] ;
        for(int i = 0 ; i < n ; i++) cin >> b[i] ;

        for(int i = 0 ; i < n ; i++) {
            if(a[i] > b[i]) {
                a.erase(a.end() - 1);
                a.insert(a.begin() , b[i]);
                c++ ;
            }
        }

        cout << c << endl ;
    }
    return 0;
}