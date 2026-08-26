class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::map<char, int>, std::vector<std::string>> anags;

        for(std::string word: strs){
            std::map<char, int> letter_count;

            for(char letter : word){
                if(letter_count.contains(letter)){
                    letter_count[letter]++;
                }else{
                    letter_count.insert({letter, 1});
                }
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
