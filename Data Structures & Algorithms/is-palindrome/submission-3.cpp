class Solution {
public:
    bool isPalindrome(string s) {
        std::queue<char> q;
        std::stack<char> st;

        for(char letter: s){
            if((letter >= 97 && letter <=122) || (letter >= 65 && letter <=90) || (letter >= 48 && letter <=57)){
                q.push(letter);
                st.push(letter);
            }

        }

        for( int i = 0 ; i < st.size() ; i++){
            if(std::tolower(q.front()) != std::tolower(st.top())) return false;
            q.pop();
            st.pop();
        }
        return true;
    }
};
