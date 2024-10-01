#include <bits/stdc++.h>
using namespace std;

bool canFinish(long long mid, int N, int M, const vector<long long>& T, const vector<long long>& F) {
    vector<long long> worker_time(N, 0LL);
    for (int j = 0; j < M; ++j) {
        long long start_time = 0;
        for (int i = 0; i < N; ++i) {
            long long process_time = T[i] * F[j];
            start_time = max(start_time, (i == 0 ? 0LL : worker_time[i - 1]));
            worker_time[i] = start_time + process_time;

            if (worker_time[i] > mid) return false;
            start_time = worker_time[i];
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M;
    cin >> N >> M;
    vector<long long> T(N), F(M);
    for (int i = 0; i < N; ++i) cin >> T[i];
    for (int j = 0; j < M; ++j) cin >> F[j];

    long long left = 0, right = 1e14, ans = right;
    while (left <= right) {
        long long mid = (left + right) >> 1;
        if (canFinish(mid, N, M, T, F)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
