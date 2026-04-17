class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::set<int> seen;

        for(unsigned i = 0; i < nums.size(); i++){
            if(seen.contains(nums[i])){
                return true;
            }
            seen.insert(nums[i]);
        }
        return false;
    }
};