#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        
        if (s.length() != t.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); i++) {
            map1[s[i]]++;
            map2[t[i]]++;
        }

        return map1 == map2;
    }
};