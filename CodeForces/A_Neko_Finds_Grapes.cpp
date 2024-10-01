#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    vector<int> odd, even ;
    int n, m ; 
    cin >> n >> m ; 

    for(int i = 0 ; i < n ; i++) {
        int x ; 
        cin >> x ;
        if(x%2 == 0) even.push_back(x) ;
        else odd.push_back(x) ;
    }

    long long a = 0, b = 0 ; 

    for(int i = 0 ; i < m ; i++) {
        int x; 
        cin >> x ;
        if(x%2 == 0 && a < odd.size()) a++ ;
        else if(x%2 == 1 && b < even.size()) b++ ;
    }

    cout << a + b << endl ; 
}