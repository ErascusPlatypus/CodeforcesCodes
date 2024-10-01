#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int minInvitations(vector<int>& p) {
    int n = p.size();
    int minInvites = 0;
    vector<bool> invited(n, false); // Track if a friend or their best friend has been invited

    for (int i = 0; i < n; ++i) {
        if (invited[i]) // Skip if friend already invited
            continue;

        unordered_set<int> seen; // Track visited friends to handle cycles
        int curFriend = i;

        while (true) {
            if (curFriend == -1 || seen.count(curFriend)) // No best friend or cycle detected
                break;

            seen.insert(curFriend);
            curFriend = p[curFriend] - 1; // Adjust to 0-based indexing

            if (invited[curFriend]) // Best friend already invited
                break;

            invited[curFriend] = true;
            if (p[curFriend] != i + 1) // If best friend is not friend themselves, count invite
                minInvites++;
            
            curFriend = p[curFriend] - 1; // Move to best friend's best friend
        }
    }

    return minInvites;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        int minInvites = minInvitations(p);
        cout << minInvites << endl;
    }

    return 0;
}
