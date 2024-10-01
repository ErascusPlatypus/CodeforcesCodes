/*

1 7            8  2
3 9            10 4
5 11           12 6

3          
1 3 5    2 4 6 

1 15        16
3 17        18
5 19        20
7 21        22
9 23        24
11   


*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> calculateUnloadingOrder(int n, int m) {
    vector<int> leftWindow, rightWindow, leftNonWindow, rightNonWindow;

    // Step 1: Load cargo according to the given pattern
    for (int i = 1; i <= m; ++i) {
        if (i <= 2 * n) {
            // Window compartments
            if ((i % 2) == 1) {
                leftWindow.push_back(i);
            } else {
                rightWindow.push_back(i);
            }
        } else {
            // Non-window compartments
            int idx = i - 2 * n;
            if ((idx % 2) == 1) {
                leftNonWindow.push_back(i);
            } else {
                rightNonWindow.push_back(i);
            }
        }
    }

    // Step 2: Unload cargo in the specified order
    vector<int> unloadingOrder;

    // Alternate between left and right compartments for non-window compartments
    for (int i = 0; i < n; ++i) {
        if (i < leftNonWindow.size()) unloadingOrder.push_back(leftNonWindow[i]);
        if (i < leftWindow.size()) unloadingOrder.push_back(leftWindow[i]);

        if(i < rightNonWindow.size()) unloadingOrder.push_back(rightNonWindow[i]);
        if (i < rightWindow.size()) unloadingOrder.push_back(rightWindow[i]);
        
    }

    // // Alternate between left and right compartments for window compartments
    // for (int i = 0; i < n; ++i) {
    //     if (i < leftWindow.size()) unloadingOrder.push_back(leftWindow[i]);
    //     if (i < rightWindow.size()) unloadingOrder.push_back(rightWindow[i]);
    // }

    return unloadingOrder;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> result = calculateUnloadingOrder(n, m);

    for (int cargo : result) {
        cout << cargo << " ";
    }
    cout << endl;

    return 0;
}
