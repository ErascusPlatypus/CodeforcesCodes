#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n ;
    cin >> n ;

    string poke ;
    cin >> poke ;

    unordered_map<char, int> mp ;
    for(char ele : poke) {
        mp[ele]++ ;
    }

    int l = 0, r = 0, mini = 1e9 ;
    unordered_map<char, int> test ;

    while(r < n) {
        test[poke[r]]++ ;

        while(test.size() >= mp.size()) {
            mini = min(mini, r-l+1) ;

            test[poke[l]]-- ;
            if(test[poke[l]] == 0) test.erase(poke[l]); 
            l++ ;
        }

        r++ ;
    }

    cout << mini << endl ;

    return 0;
}