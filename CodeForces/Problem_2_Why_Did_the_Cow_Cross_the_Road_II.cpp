#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n, k, b ;
    cin >> n >> k >> b ;

    vector<int> broke(n+1, 0) ;
    for(int i = 0 ; i < b ; i++) {
        int x ;
        cin >> x ;
        broke[x] = 1 ;
    }

    vector<int> pre(n+1, 0) ;
    for(int i = 1 ; i <= n ; i++) {
        pre[i] = pre[i-1] + broke[i] ;
    }

    int mini = 1e9 ;
    for(int i = k ; i <= n ; i++) {
        int br = pre[i] - pre[i - k] ;
        mini = min(mini, br) ;
    }

    cout << mini << endl ;
}
