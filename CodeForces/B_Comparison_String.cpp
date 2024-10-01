#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;
        
        int ans = 1, val = 1;
        for(int i = 1; i < n; i++)
        {
            if(s[i] != s[i - 1]) val = 1;
            else val++;
            ans = max(ans, val);
        }
        cout << ans + 1 << endl;
    }
    return 0;
}