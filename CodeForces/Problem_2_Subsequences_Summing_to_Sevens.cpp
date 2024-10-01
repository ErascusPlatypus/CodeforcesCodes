#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n ; 
    cin >> n ;

    vector<int> cows(n) ;
    for(int i = 0; i < n; i++) {
        cin >> cows[i];
    }


    vector<int> mod(7, -1) ;
    mod[0] = 0 ;
    int sum = 0 , maxi = 0; 
    for(int i = 1 ; i <= n ; i++) {
        sum += cows[i-1] ;

        int m = ((sum % 7) + 7) % 7 ; 
        if(mod[m] == -1) mod[m] = i ; 
        else maxi = max(maxi, i - mod[m]) ;
    }

    cout << maxi << endl ;
    return 0;
}