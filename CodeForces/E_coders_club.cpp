#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


int f(vector<int> arr, int k) {
    int n = arr.size();
    if(k == 1) {
        return *min_element(arr.begin(), arr.end());
    }

    if(k==2) {
        return max(arr[0], arr[n-1]) ;
    }

    return *max_element(arr.begin(), arr.end());
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << f(arr, k) << endl;
    return 0;
}