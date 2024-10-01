#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;

    // Read the input sequence of elements
    vector<char> seq(N);
    for (int i = 0; i < N; i++) {
        cin >> seq[i];
    }

    // dp[i] will store the number of ways to indent the first i elements
    vector<long long> dp(N + 1, 0);
    dp[0] = 1;  // There's one way to indent an empty sequence (the base case)

    for (int i = 1; i <= N; i++) {
        if (seq[i - 1] == 's') {
            // Simple element, it can just extend the current indentation
            dp[i] = dp[i - 1];
        } else if (seq[i - 1] == 'f') {
            // Framework element, we need to count all previous valid sequences
            for (int j = i - 1; j >= 0; j--) {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
    }

    // The result is the number of ways to indent the entire sequence
    cout << dp[N] << endl;
    return 0;
}
