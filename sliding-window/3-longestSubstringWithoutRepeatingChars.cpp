#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int maxWindow = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];  // 'right' is just an index right now. need to keep track of the actual letter

            while (window.count(c) > 0) { // checking to see if c is in the window
                window.erase(s[left]);
                left++; // moving left pointer +1
            }

            // since there's no repeats, it's safe to add c
            window.insert(c);

            // update maxWindow length
            maxWindow = max(maxWindow, right - left + 1);

        }

        return maxWindow;
    }
};