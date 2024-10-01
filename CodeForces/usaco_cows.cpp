#include <bits/stdc++.h>
using namespace std ;
#define int long long

int32_t main() {
    ifstream infile("div7.in");
    ofstream outfile("div7.out");

    int n ;
    infile >> n ;

    vector<int> cows(n) ;
    for(int i = 0 ; i < n ; i++) {
        infile >> cows[i] ;
    }

    vector<int> occ(7, -1) ;
    occ[0] = 0 ;

    int sum = 0 ;
    int l = 0 ;

    for(int i = 0 ; i < n ; i++) {
        sum += cows[i] ;
        int rem = sum % 7 ;

        if(occ[rem] == -1) {
            occ[rem] = i + 1 ;
        }
        else {
            int len = i + 1 - occ[rem] ;
            if(len > l) {
                l = len ;
            }
        }
    }

    outfile << l << endl ;

    infile.close();
    outfile.close();

    return 0 ;
}