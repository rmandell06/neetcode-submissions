class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> seen;

        for( int i = 0 ; i < nums.size() ; i++ ){
            if(seen.contains(target - nums[i])) return {seen.at(target - nums[i]), i};
            seen.insert({nums[i], i});
        }
        // return {0,0};
    }
   
};
