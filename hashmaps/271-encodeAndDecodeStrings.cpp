#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        
        for (int i = 0; i < strs.size(); i++) {
            result += to_string(strs[i].length()) + "#" + strs[i];
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.length()) {
            // finding the '#' that marks the end of the length of digits
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            // convert the digits between i and j into an actual integer
            int len = stoi(s.substr(i, j - i));
            // actual string starts right after '#'
            string word = s.substr(j + 1, len);
            result.push_back(word);
            i = j + 1 + len;
        }
        return result;
    }
};
