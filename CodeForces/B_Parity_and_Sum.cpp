#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n ;
        cin >> n ; 

        vector<int> vec(n) ;
        int even = 0 , odd = 0 ;

        vector<int> eves ;
        int s = -1 ;

        for(int i = 0 ; i < n ; i++) {
            cin >> vec[i] ;

            if(vec[i] % 2 == 0) eves.push_back(vec[i]);
            else if (vec[i] > s) s = vec[i] ;
        }

        sort(eves.begin(), eves.end()) ;

        if (s==-1 || eves.size()==0) {
            cout << 0 << endl ;
            continue;
        }

        int ans = eves.size() ;

        for(int t : eves) {
            if (t < s) {
                s += t ;
            }
            else {
                ans += 1 ;
                break ;
            }
        }

        cout << ans << endl ;    
    }
    return 0;
}