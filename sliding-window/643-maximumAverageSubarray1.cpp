#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double windowSum = 0;

        // sum the first k numbers for first window
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }
        
        double maxSum = windowSum; // best sum seen so far

        // sliding window
        for (int i = k; i < nums.size(); i++) {
            windowSum += nums[i]; // add new element entering on the right
            windowSum -= nums[i - k]; // remove old element leaving on the left
            maxSum = max(maxSum, windowSum); // update best sum
        }

        return maxSum / k;
    }
};