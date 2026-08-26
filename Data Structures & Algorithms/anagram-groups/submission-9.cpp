class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> groups;

        for (const std::string& word : strs) {
            std::array<int, 26> count{};        // zero-initialized
            for (char c : word) count[c - 'a']++;

            std::string key;
            for (int n : count) { key += '#'; key += std::to_string(n); }  // '#' so [1,11] != [11,1]
            groups[key].push_back(word);
        }

        std::vector<std::vector<std::string>> result;
        for (auto& [k, v] : groups) result.push_back(std::move(v));
        return result;
    }
};