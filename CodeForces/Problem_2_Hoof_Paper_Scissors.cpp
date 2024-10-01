#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n ;
    cin >> n ;

    vector<char> fj(n) ;
    for(int i = 0 ; i < n ; i++) {
        cin >> fj[i] ;
    }

    vector<int> preh(n+1, 0), prep(n+1, 0), pres(n+1, 0) ;
    vector<int> sufh(n+1, 0), sufp(n+1, 0), sufs(n+1, 0) ;

    for(int i = 1 ; i <= n ; i++) {
        preh[i] = preh[i-1] + (fj[i-1] == 'S') ;
        prep[i] = prep[i-1] + (fj[i-1] == 'H') ;
        pres[i] = pres[i-1] + (fj[i-1] == 'P') ;  
    }

    for(int i = n-1 ; i >= 0 ; i--) {
        sufh[i] = sufh[i+1] + (fj[i] == 'S') ; 
        sufp[i] = sufp[i+1] + (fj[i] == 'H') ;
        sufs[i] = sufs[i+1] + (fj[i] == 'P') ; 
    }

    int maxi = 0 ;
    for(int i = 0 ; i <= n ; i++) {
        maxi = max(maxi, preh[i] + sufp[i]) ;
        maxi = max(maxi, preh[i] + sufs[i]) ;
        maxi = max(maxi, prep[i] + sufh[i]) ;
        maxi = max(maxi, prep[i] + sufs[i]) ; 
        maxi = max(maxi, pres[i] + sufh[i]) ;
        maxi = max(maxi, pres[i] + sufp[i]) ;
    }

    cout << maxi << endl ;


    return 0;
}