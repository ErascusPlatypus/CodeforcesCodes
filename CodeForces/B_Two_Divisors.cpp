#include <bits/stdc++.h>
using namespace std;
#define int long long

int LCM(int a, int b) 
{ 
    int greater = max(a, b); 
    int smallest = min(a, b); 
    for (int i = greater; ; i += greater) { 
        if (i % smallest  == 0) 
            return i; 
    } 
} 

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int a , b ;
        cin >> a >> b ;

        if(a == 1) {
            cout << b * b << endl ; 
            continue ;
        }
        if(b == 1) {
            cout << a * a << endl ;
            continue;
        }

        int lcm = LCM(a , b) ;
        cout << lcm << endl ;


    }
    return 0;
}