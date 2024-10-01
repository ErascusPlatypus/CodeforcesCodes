#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> gangs(n);
    for (int i = 0; i < n; i++) {
        cin >> gangs[i];
    }

    // Find first district with a different gang (pivot)
    int pivot = -1;
    for (int i = 1; i < n; i++) {
        if (gangs[i] != gangs[0]) {
            pivot = i;
            break;
        }
    }

    if (pivot == -1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    vector<pair<int, int>> roads;

    // Connect all districts of the same gang as 0 to pivot
    for (int i = 1; i < n; i++) {
        if (gangs[i] == gangs[0]) {
            roads.emplace_back(pivot + 1, i + 1);
        } else {
            roads.emplace_back(1, i + 1);
        }
    }

    for (auto [u, v] : roads) {
        cout << u << " " << v << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
