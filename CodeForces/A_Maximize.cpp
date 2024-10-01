#include <bits/stdc++.h>
using namespace std;

int gcd(int a , int b) {
    return b == 0 ? a : gcd(b, a % b);    
}

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int x ;
        cin >> x ;

        int z = x-1 ;

        while(z > 0) {
            if(gcd(x,z) + z == x) {
                cout << z << endl ;
                break ;
            }
            z-- ;
        }
    }
    return 0;
}