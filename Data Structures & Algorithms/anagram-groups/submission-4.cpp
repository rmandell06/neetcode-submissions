class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::vector<int>, std::vector<std::string>> anags;

        for(std::string word: strs){
            std::vector<int> letter_count(26, 0);

            for(char letter : word){
                letter_count[letter - 'a']++;
            }

            if(anags.contains(letter_count)){
                anags[letter_count].push_back(word);
            }else{
                anags.insert({letter_count, {word}});
            }
        }

        std::vector<std::vector<std::string>> lists;

        for(auto& [key, value] : anags){
            lists.push_back(value);
        }
        
        return lists;
    }
};
