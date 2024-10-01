#include <bits/stdc++.h>
using namespace std;

vector<int> getDivisors(int n) {
    vector<int> div;
    for(int i = 1; i*i <= n; i++) {
        if(n % i == 0) {
            div.push_back(i);
            if(i*i != n) div.push_back(n/i);
        }
    }
    sort(div.begin(), div.end());
    return div;
}

bool solve_rec(vector<int>& a, int pos, int prev) {
    if(pos == a.size()) return true;
    
    vector<int> divs = getDivisors(a[pos]);
    for(int d : divs) {
        if(d > prev) {
            if(solve_rec(a, pos+1, d)) return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    if(solve_rec(a, 0, 0)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}