#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int t ;
    cin >> t ;

    while(t--) {
        int n, m, x ;
        cin >> n >> m >> x ;
        
        set<int> pos = {x} ;
        for(int i = 0 ; i < m ; i++) {
            int a ;char c ; 
            cin >> a >> c ; 
            set<int> npos ;

            for(int p : pos) {
                int cw = (p + a - 1) % n + 1 ;
                int ccw = (p - a - 1 + n) % n + 1 ;

                if(c == '1') {
                    npos.insert(ccw) ;
                }
                else if(c == '0') {
                    npos.insert(cw) ;
                }
                else {
                    npos.insert(cw) ;
                    npos.insert(ccw) ; 
                }
            }

            pos = npos ; 
        }

        cout << pos.size() << endl ; 
        for(int p : pos) {
            cout << p << " " ;
        }
        cout << endl ; 
    }
    return 0;
}