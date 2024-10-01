#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n, q;
    cin >> n >> q;

    vector<int> breed(n);
    for (int i = 0; i < n; i++) cin >> breed[i];

    vector<int> ones(n, 0), twos(n, 0), threes(n, 0);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            ones[i] = ones[i - 1];
            twos[i] = twos[i - 1];
            threes[i] = threes[i - 1];
        }
        if (breed[i] == 1) ones[i]++;
        else if (breed[i] == 2) twos[i]++;
        else if (breed[i] == 3) threes[i]++;
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r; 
        l--; r--;     
        
        int onesCount = ones[r] - (l > 0 ? ones[l - 1] : 0);
        int twosCount = twos[r] - (l > 0 ? twos[l - 1] : 0);
        int threesCount = threes[r] - (l > 0 ? threes[l - 1] : 0);
        
        cout << onesCount << " " << twosCount << " " << threesCount << endl;
    }

    return 0;
}
