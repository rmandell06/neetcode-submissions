class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::map<int, int> count;

        for(auto& num : nums){
            if(count.contains(num)) count.erase(num);
            else{
                count.insert({num, 1});
            }
        }

        for(auto& num : count){
            return num.first;
        }
    }
};
