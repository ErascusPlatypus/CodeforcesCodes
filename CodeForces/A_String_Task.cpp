#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    string s;
    cin >> s;
    int n = s.length();
    string res = "";

    for (int i = 0; i < n; i++) {
        char x = s[i];
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o'
            || x == 'u' || x == 'A' || x == 'E' || x == 'I'
            || x == 'O' || x == 'U') {
            continue;
        } 
        else {
            res += '.';
            if (isupper(x)) { 
                res += tolower(x);
            } 
            else {
                res += x;
            }
        }
    }

    cout << res << endl;

    return 0;
}
