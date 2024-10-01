#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int calculateTShirts(int n, const string &s) {
    unordered_set<char> firstSolved; 
    int tShirts = 0;

    for (char problem : s) {
        if (firstSolved.find(problem) == firstSolved.end()) {
            tShirts += 2;
            firstSolved.insert(problem);
        } else {
            tShirts += 1;
        }
    }

    return tShirts;
}

int main() {
    int t; 
    cin >> t;

    vector<int> results(t);

    for (int i = 0; i < t; ++i) {
        int n;
        string s;
        cin >> n >> s;

        results[i] = calculateTShirts(n, s);
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
