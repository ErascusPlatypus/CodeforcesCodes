#include <bits/stdc++.h>
using namespace std;

int main() {
    string a ;
    cin >> a ;

    int n = a.size() ;
    int res = 0 ;

    res = (1 << n) - 2 ;
    int pos = 0 ; 

    for(int i = n-1 ; i >= 0 ; i--) {
        if(a[i] == '7') {
            res += (1 << pos) ;
        } 

        pos++ ;
    }

    res++ ;
    cout << res << endl;




    return 0;
}