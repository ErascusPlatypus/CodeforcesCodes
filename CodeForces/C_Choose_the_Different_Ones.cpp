#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isPossible(const vector<int>& a, const vector<int>& b, int k) {
    map<int, int> freqA, freqB;
    
    // Count frequencies in array a
    for (int num : a) {
        freqA[num]++;
    }
    
    // Count frequencies in array b
    for (int num : b) {
        freqB[num]++;
    }

    // Check if numbers from 1 to k have frequency greater than 1 in both arrays
    for (int i = 1; i <= k; i++) {
        if (freqA[i] < 1 || freqB[i] < 1) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        if (isPossible(a, b, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
