#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, p;
        cin >> n >> p;

        vector<pair<int, int>> residents(n);
        for (int i = 0; i < n; i++) cin >> residents[i].second;
        for (int i = 0; i < n; i++) cin >> residents[i].first;

        sort(residents.begin(), residents.end());

        priority_queue<int> pq;
        pq.push(residents[0].second);

        int sum = p + residents[0].first;
        for (int i = 1; i < n; i++) {
            while (!pq.empty() && pq.top() > residents[i].second) {
                pq.pop();
                sum += p;
            }
            pq.push(residents[i].second);
            sum += residents[i].first;
        }

        cout << sum << "\n";
    }

    return 0;
}
