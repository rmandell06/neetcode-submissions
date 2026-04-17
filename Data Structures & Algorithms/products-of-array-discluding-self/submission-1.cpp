class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> output(nums.size(), 0);
        int prefix = 1;

        for(unsigned i = 0 ; i < nums.size() ; ++i){
            if(i == 0){
                output[0] = prefix;
            }else{
                prefix *= nums[i - 1];
                output[i] = prefix;
            }
        }

        int postfix = 1;
        for(int i = nums.size() - 1; i >= 0 ; --i){
            output[i] *= postfix;
            postfix *= nums[i];
        }
        
        return output;
    }
};

// int product = nums[0];
// int zero_count = 0;

// for(unsigned i = 1 ; i < nums.size() ; ++i){
//     if(nums[i] != 0){
//         product *= nums[i];
//     }else{
//         zero_count++;
//     }
// }

// if(zero_count > 1){
//     return std::vector<int>(nums.size(), 0);
// }

// std::vector<int> output;

// for(auto& num : nums){
//     if(num != 0 && !zero_count){
//         output.push_back(product / num);
//     }else if(zero_count && num == 0){
//         output.push_back(product);
//     }else{
//         output.push_back(0);
//     }
// }

// return output;
