#include <bits/stdc++.h>
using namespace std;

bool is_mirror(char c) {
    return string("AHIMOTUVWXY").find(c) != string::npos;
}

int main() {
    string s;
    cin >> s;

    string st = s;
    reverse(s.begin(), s.end());

    if (s.length() == 1) {
        if (is_mirror(s[0])) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else if (s == st) {
        bool all_mirror = true;
        for (char c : s) {
            if (!is_mirror(c)) {
                all_mirror = false;
                break;
            }
        }
        if (all_mirror) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
