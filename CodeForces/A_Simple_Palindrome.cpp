#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n ;
        cin >> n ;

        int ind = n % 5 ;
        string s = "" ;
        vector<char> vows = {'a', 'e', 'i', 'o', 'u'} ;
        int i = 0 ;
        int len = 0 ;
        while(len < n) {
            s += vows[i] ;
            i++ ;
            i = i % 5 ;
            len++ ;
        }
        
        

        cout << s << endl ;
    }
    return 0;
}