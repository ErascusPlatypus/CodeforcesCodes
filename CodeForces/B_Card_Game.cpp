#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, x, y ;
        cin >> a >> b >> x >> y ;
        int count = 0 ; 

        if((a > x && b >= y) || (a >= x && b > y)) count++ ;
        if((a > y && b >= x) || (a >= y && b > x)) count++ ;
        if((b > y && a >= x) || (a > x && b >= y)) count++ ;
        if((b > x && a >= y) || (b >= x && a > y)) count++ ;

        cout << count << endl ;

    }
    return 0;
}