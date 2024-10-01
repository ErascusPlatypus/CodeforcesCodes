#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int x, y, k ;
        cin >> x >> y >> k ;
        int count = 0 ;

        count = (x+k-1)/k + (y+k-1)/k ;

        cout << count << endl ;
    }
    return 0;
}