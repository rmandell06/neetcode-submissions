class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        groups.reserve(strs.size());

        for (string& s : strs) {
            string key(26, 0);                 // fixed 26-byte key
            for (char c : s) key[c - 'a']++;   // count as raw bytes
            groups[key].push_back(move(s));    // steal the string, no copy
        }

        vector<vector<string>> res;
        res.reserve(groups.size());
        for (auto& [k, v] : groups) res.push_back(move(v));
        return res;
    }
};