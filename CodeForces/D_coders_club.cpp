#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n ;
    cin >> n ;

    string s ;
    cin >> s; 

    int l = 0, r = 0, u = 0, d = 0;
    for(char c : s) {
        if(c == 'L') l++;
        if(c == 'R') r++;
        if(c == 'U') u++;
        if(c == 'D') d++;
    }

    int x = min(l, r) * 2;
    int y = min(u, d) * 2;

    cout << x+y << endl ;

    return 0;
}