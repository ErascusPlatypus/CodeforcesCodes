#include <bits/stdc++.h>
using namespace std ;

int main() {
    int t ;
    cin >> t ;
    
    while(t--) {
        string s ;
        cin >> s; 

        int n = s.length() ;
        string res = "" ;
        if(n > 10) {
            res += s[0] ;
            res += to_string(n-2) ;
            res += s[n-1] ;
        }
        else {
            res += s ;
        }

        cout << res << endl ;
    }
}