#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<int, int>> monsters(n); // pair to store health modulo and index
        
        for (int i = 0; i < n; ++i) {
            int health;
            cin >> health;
            int mod_health = health % k;
            if (mod_health == 0) mod_health = k; // if divisible by k, make it k
            monsters[i] = {mod_health, i}; // store mod value and original index
        }
        
        // Sort by mod_health in descending order, but preserve the original index order in case of ties
        stable_sort(monsters.begin(), monsters.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        
        // Output the 1-based index of monsters in the sorted order
        for (auto &m : monsters) {
            cout << m.second + 1 << ' ';
        }
        cout << endl;
    }
}
