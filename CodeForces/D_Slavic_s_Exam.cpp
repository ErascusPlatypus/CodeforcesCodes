#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        string s, t;
        cin >> s >> t;

        int len1 = s.length(), len2 = t.length();

        if (len2 > len1) {
            cout << "NO" << endl;
            continue;
        }

        int j = 0;  
        for (int i = 0; i < len1; i++) {
            if (j < len2 && (s[i] == t[j] || s[i] == '?')) {
                s[i] = t[j]; 
                j++;  
            } else if (s[i] == '?') {
                s[i] = 'a';
            }
        }

        if (j == len2) {
            cout << "YES" << endl;
            cout << s << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
