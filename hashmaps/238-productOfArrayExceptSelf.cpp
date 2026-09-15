#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int product = 1;
        int num = 0;
        int zeros = 0;
        int index = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeros++;
                index = i;
            } else {
                product *= nums[i];
            }
        }
        if (zeros == 0) {
            for (int i = 0; i < nums.size(); i++) {
                result[i] = product / nums[i];
            }
        } else if (zeros == 1) {
            result[index] = product;
        }
    
        return result;
    }
};
