class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        std::map<char, unsigned> w1;
        std::map<char, unsigned> w2;

        for(unsigned i = 0; i < s.length(); i++){
            w1[s[i]]++;
            w2[t[i]]++;
        }

        return w1 == w2;
    }
};
