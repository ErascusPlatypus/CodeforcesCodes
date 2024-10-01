#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        int total_k = 0;
        for (auto num : nums)
        {
            if (num == k) {
                total_k++;
            }
        }
        int max_gain = 0;
        for (int v = 1; v <= 50; v++)
        {
            if (v == k)
                continue;
            int x = k - v;
            int current_sum = 0;
            int local_max = 0;
            for (auto num : nums)
            {
                if (num == v) {
                    current_sum += 1;
                }
                else if (num == k) {
                    current_sum -= 1;
                }
                if (current_sum < 0) {
                    current_sum = 0;
                }
                if (current_sum > local_max) {
                    local_max = current_sum;
                }
            }
            if (local_max > max_gain) {
                max_gain = local_max;
            }
        }
        int max_freq = total_k + max_gain;
        return max_freq;
    }
};