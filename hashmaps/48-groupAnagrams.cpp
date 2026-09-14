#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (int i = 0; i < strs.size(); i++) {
            string word = strs[i]; // keeping track of the word
            string key = word; // this will be put in alphabetical order to add to the proper "group"
            sort(key.begin(), key.end()); // rearranging the word in alphabetical order
            groups[key].push_back(word); // add original word to its group
        }

        vector<vector<string>> result;
        for (auto& [key, group] : groups) {
            result.push_back(group);
        }
        return result;
    }
};