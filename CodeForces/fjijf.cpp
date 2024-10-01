#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <algorithm>

class Solution {
private:
    // Helper function to calculate GCD using Euclidean algorithm
    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    // Helper function to calculate LCM using GCD
    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }
    
    // Helper function to update GCD excluding one number
    long long updateGCD(vector<int>& nums, vector<long long>& prefixGCD, vector<long long>& suffixGCD, int skipIndex) {
        if (skipIndex == 0) return suffixGCD[1];
        if (skipIndex == nums.size() - 1) return prefixGCD[nums.size() - 2];
        return gcd(prefixGCD[skipIndex - 1], suffixGCD[skipIndex + 1]);
    }
    
    // Helper function to update LCM excluding one number
    long long updateLCM(vector<int>& nums, vector<long long>& prefixLCM, vector<long long>& suffixLCM, int skipIndex) {
        if (skipIndex == 0) return suffixLCM[1];
        if (skipIndex == nums.size() - 1) return prefixLCM[nums.size() - 2];
        return lcm(prefixLCM[skipIndex - 1], suffixLCM[skipIndex + 1]);
    }

public:
    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return (long long)nums[0] * nums[0];
        
        vector<long long> prefixGCD(n), suffixGCD(n);
        vector<long long> prefixLCM(n), suffixLCM(n);
        
        prefixGCD[0] = nums[0];
        prefixLCM[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixGCD[i] = gcd(prefixGCD[i-1], nums[i]);
            prefixLCM[i] = lcm(prefixLCM[i-1], nums[i]);
        }
        
        suffixGCD[n-1] = nums[n-1];
        suffixLCM[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            suffixGCD[i] = gcd(suffixGCD[i+1], nums[i]);
            suffixLCM[i] = lcm(suffixLCM[i+1], nums[i]);
        }
        
        long long maxScore = suffixGCD[0] * suffixLCM[0];  
        
        for (int i = 0; i < n; i++) {
            long long currentGCD = updateGCD(nums, prefixGCD, suffixGCD, i);
            long long currentLCM = updateLCM(nums, prefixLCM, suffixLCM, i);
            maxScore = max(maxScore, currentGCD * currentLCM);
        }
        
        return maxScore;
    }
};


int main() {
    vector<int> nums = {6,14,20};
    Solution sol;
    cout << sol.maxScore(nums) << endl;
    return 0;
}
