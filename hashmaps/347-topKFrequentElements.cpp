#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        priority_queue<pair<int, int>> pq;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        for (auto& [value, count] : map) {
            pq.push({count, value}); // count first, so that pq sorts by count
        }
        for (int i = 0; i < k; i++) {
            result.push_back(pq.top().second); // second is value, not count
            pq.pop();
        }
        return result;
    }
};
