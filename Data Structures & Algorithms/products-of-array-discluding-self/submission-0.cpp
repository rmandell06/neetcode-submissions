class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = nums[0];
        int zero_count = 0;

        for(unsigned i = 1 ; i < nums.size() ; ++i){
            if(nums[i] != 0){
                product *= nums[i];
            }else{
                zero_count++;
            }
        }

        if(zero_count > 1){
            return std::vector<int>(nums.size(), 0);
        }

        std::vector<int> output;

        for(auto& num : nums){
            if(num != 0 && !zero_count){
                output.push_back(product / num);
            }else if(zero_count && num == 0){
                output.push_back(product);
            }else{
                output.push_back(0);
            }
        }

        return output;
    }
};
