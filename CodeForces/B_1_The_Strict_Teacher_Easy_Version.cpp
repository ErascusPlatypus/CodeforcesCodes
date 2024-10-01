#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    int t;  
    cin >> t;

    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;  
        
        vector<int> teachers(m);    
        for (int i = 0; i < m; i++) {
            cin >> teachers[i]; 
        }
        int david;
        cin >> david; 

        int add = abs(david - teachers[0]);
        int sub = abs(david - teachers[1]);
        
        cout << min(add, sub) << endl;
    }
    return 0;
}