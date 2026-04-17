class Solution {
public:
    //Hashmap
    //Key is char array, this leads to comparing array at each key
    //To improve, 
    //Value is vector of ones that match
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        std::map<std::map<char, int>, std::vector<std::string>> anags;

        for(auto& word : strs){
            std::map<char, int> letters;
            for ( char letter : word){
                if(letters.contains(letter)) letters[letter]++;
                else{
                    letters.insert({letter, 1});
                }
            }
            if(anags.contains(letters)){
                anags[letters].push_back(word);
            }else{
                anags.insert({letters, {word}});
            }
        }

        std::vector<std::vector<std::string>> vec;

        for(auto [key, value] : anags){
            vec.push_back(value);
        } 

        return vec;       
    }
};
