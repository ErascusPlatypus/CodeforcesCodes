#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Movie {
    int st ;
    int end ;  
};

bool custComp(Movie &i, Movie &j) {
    return i.end < j.end ;
}

int32_t main() {
    int t;
    cin >> t;

    vector<Movie> times(t) ;

    for (int i = 0 ; i < t ; i++) {
        cin >> times[i].st >> times[i].end ;
    }

    sort(times.begin() , times.end(), custComp) ;

    int c = 0 , last = 0 ;

    for(int i = 0 ; i < t ; i++) {
        if(times[i].st >= last) {
            c++ ;
            last = times[i].end ;
        }
    }

    cout << c << endl  ;

    
    return 0;
}