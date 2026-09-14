#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int complement = 0;

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            complement = target - nums[i];
            if (map.count(complement) > 0 && map[complement] != i) {
                return {i, map[complement]};
            }
        }
        return {};
    }
};
