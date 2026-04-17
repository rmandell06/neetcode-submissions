class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;

        for (char letter : s){
            if(!stack.empty()){
                if(letter == '}' && stack.top() == '{') stack.pop();
                else if(letter == ')' && stack.top() == '(') stack.pop();
                else if(letter == ']' && stack.top() == '[') stack.pop();
                else{
                    stack.push(letter);
                }
            }else{
                stack.push(letter);
            }
        }

        return stack.empty();
    }
};
