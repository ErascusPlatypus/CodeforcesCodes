#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long count_multiples(long long i, long long l, long long r) {
    return (r / i) - ((l - 1) / i);
}

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        long long l, r, k;
        cin >> l >> r >> k;
        
        long long c = 0;  
        long long curr = l;  

        while (curr <= r) {
            bool found = false;

            for (long long i = curr; i <= r; ++i) {
                if (count_multiples(i, curr, r) >= k) {
                    c++;
                    curr = i + 1; 
                    found = true;
                    break;
                }
            }
            
            if (!found) break;
        }
        
        cout << c << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
