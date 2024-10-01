#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n ; 
        cin >> n ;
        if(n < 4) {
            cout << -1 << endl ; 
            continue;
        }

        vector<int> arr(n) ;
        unordered_map<int, int> mp ;
        int f = 0 ; int dub = 0 ; 
        for(int i = 0 ; i < n ; i++) {
            cin >> arr[i] ;
            mp[arr[i]]++; 
            if(mp[arr[i]] == 2) {
                f++ ;
                dub = arr[i] ;
            }
        }

        if(f == 0) {
            cout << -1 << endl ;
            continue; 
        }

        cout << dub << " " << dub << " " ;
        mp[dub] -= 2 ;
        int cnt = 0 ; 
        for(int i = 0 ; i < 2 ; i++) {
                
                cout << arr[i] << " " ;
                cnt++ ;
            }
        }

        cout << endl ; 
    }
    return 0;
}